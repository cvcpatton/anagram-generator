# Anagram Generator 🔤  
(In process, September 23, 2025)  
A console-based C++ application that generates anagrams of a user-provided word. Demonstrates string manipulation, loops, and randomization.

**Features**  
* Accepts user input of any word.  
* Generates random anagrams by shuffling characters.  
* Ensures valid permutations without repeating identical output.  
* Lightweight and runs entirely in the console.  


**Tech Stack**  
* C++ – core logic and execution  
* STL – string handling and randomization  


**How to Run**  
1. Clone this repository:  
   ```bash
   git clone https://github.com/yourusername/cpp-anagram-generator.git
   cd cpp-anagram-generator
2. Compile the program:
   g++ anagram.cpp -o anagram
3. Run the executable:
   ./anagram
 
**Sample Output**
```
Enter a name or phrase:
   hot chocolate
Anagram combinations using all letters (max 3 words):
a cloche tooth
a hooch toltec
ace cloth hoot
etc. 
```

**Compatibility Notes**

This C++ anagram generator has been tested in the following environments:

* OneCompiler.com ✅
-- Compiles and runs correctly

* OnlineGDB.com ⚠️
-- File access to 'words.csv' may not be supported; tries to compile the csv file

Recommendation: Use OneCompiler or a local compiler (C++14 or later) for best results.
