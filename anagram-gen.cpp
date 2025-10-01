/*
 * Anagram Generator, C++
 * Cathy Patton
 * September 2025
 *
 * NOTE:
 * This program compiles and runs correctly on OneCompiler.com, but may fail to compile 
 * or behave differently in OnlineGDB.com due to differences in C++ standard support and input handling. 
 *
 * Known issues with OnlineGDB:
 * - File access to 'words.csv' may not be supported. Tries to compile the csv file.
 *
 * Recommendation: Use OneCompiler or a local compiler for testing.
 */
 
// Data source for words.csv is eng_41320.csv at https://gist.github.com/diplodata/be26123b3f45a7ffab36426da2d2ee1f


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <functional>
#include <set>

using namespace std;

// Count letters a-z in a string
vector<int> letterCount(const string& s) {
    vector<int> count(26, 0);
    for (char c : s) {
        if (isalpha(c)) {
            count[tolower(c) - 'a']++;
        }
    }
    return count;
}

// Check if needed letters can be formed from available
bool canUse(const vector<int>& avail, const vector<int>& need) {
    for (int i = 0; i < 26; i++) {
        if (need[i] > avail[i])
            return false;
    }
    return true;
}

// Subtract letter counts (for backtracking)
void subtractCount(vector<int>& avail, const vector<int>& need) {
    for (int i = 0; i < 26; i++) {
        avail[i] -= need[i];
    }
}

// Add letter counts back (for backtracking)
void addCount(vector<int>& avail, const vector<int>& need) {
    for (int i = 0; i < 26; i++) {
        avail[i] += need[i];
    }
}

// Load dictionary from file (words.csv)
vector<pair<string, vector<int>>> loadDictionary(const string& filename) {
    ifstream dictFile(filename);
    if (!dictFile) {
        cerr << "Error: could not open " << filename << "\n";
        exit(1);
    }

    vector<pair<string, vector<int>>> words;
    string line;

    while (getline(dictFile, line)) {
        string word;
        for (char c : line) {
            if (isalpha(c)) word += tolower(c);
        }
        if (!word.empty()) {
            words.emplace_back(word, letterCount(word));
        }
    }

    return words;
}

// Get validated user input, alpha and space characters only 
string getValidatedInput() {
    string input;
    while (true) {
        cout << "Enter a name or phrase: ";
        if (!getline(cin, input)) {
            cerr << "\nError reading input or input stream closed. Exiting.\n";
            exit(1);
        }

        if (input.find_first_not_of(" \t\n\r") == string::npos) {
            cout << "No input received. Please enter letters only.\n\n";
            continue;
        }

        bool valid = all_of(input.begin(), input.end(), [](char c) {
            return isalpha(c) || isspace(c);
        });

        if (valid) return input;

        cout << "Input must contain only letters and spaces. No numbers or special characters.\n\n";
    }
}

// Filter candidate words based on input letters 
vector<pair<string, vector<int>>> filterCandidates(
    const vector<pair<string, vector<int>>>& words,
    const vector<int>& inputLetters
) {
    vector<pair<string, vector<int>>> candidates;
    for (const auto& entry : words) {
        if (canUse(inputLetters, entry.second)) {
            candidates.push_back(entry);
        }
    }

    sort(candidates.begin(), candidates.end()); // optional, for consistent output
    return candidates;
}

// Recursive backtracking to generate anagrams 
set<vector<string>> generateAnagrams(
    const vector<pair<string, vector<int>>>& candidates,
    const vector<int>& inputLetters,
    int maxWords = 3,
    int maxResults = 100
) {
    set<vector<string>> results;
    vector<string> currentCombo;
    vector<int> available = inputLetters;

    function<void(int, vector<int>&)> backtrack = [&](int index, vector<int>& avail) {
        if (results.size() >= maxResults) return;

        bool allUsed = all_of(avail.begin(), avail.end(), [](int x) { return x == 0; });
        if (allUsed) {
            results.insert(currentCombo);
            return;
        }

        if ((int)currentCombo.size() >= maxWords) return;

        for (int i = index; i < (int)candidates.size(); ++i) {
            const auto& word = candidates[i].first;
            const auto& count = candidates[i].second;
            if (canUse(avail, count)) {
                subtractCount(avail, count);
                currentCombo.push_back(word);
                backtrack(i, avail); // allow reuse
                currentCombo.pop_back();
                addCount(avail, count);
            }
        }
    };

    backtrack(0, available);
    return results;
}

// Display results (three-word phrases and max 100 anagrams)
void displayResults(const set<vector<string>> &results, const string &originalInput) {
    cout << "\nAnagram combinations for: \"" << originalInput << "\" (using all letters, max 3 words):\n";
    if (results.empty()) {
        cout << "No valid combinations found.\n";
    } else {
        for (const auto& combo : results) {
            for (size_t i = 0; i < combo.size(); ++i) {
                cout << combo[i];
                if (i + 1 < combo.size()) cout << " ";
            }
            cout << "\n";
        }

        if (results.size() >= 100) {
            cout << "\nShowing first 100 combinations (limit reached).\n";
        } else {
            cout << "\nTotal anagram combinations found: " << results.size() << "\n";
        }
    }
}

// Main program runs program execution
int main() {
    const string filename = "words.csv";
    auto allWords = loadDictionary(filename);
    string input = getValidatedInput();
    vector<int> inputLetters = letterCount(input);
    auto candidates = filterCandidates(allWords, inputLetters);
    auto results = generateAnagrams(candidates, inputLetters);
    displayResults(results, input);
    return 0;
}

