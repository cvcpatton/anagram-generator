# Anagram Generator 🔤  
A console-based C++ application that generates anagrams of a user-provided word. Demonstrates string manipulation, loops, and randomization.  
  
Currently caps the output at 100 anagram combinations to reduce runtime but that can be modified. Also outputs three-word phrases but could be modified to two-word or allow the user to specify how many words should be in each phrase.  
  
**Features**  
* Accepts user input of any word.  
* Generates random anagrams by shuffling characters.  
* Ensures valid permutations without repeating identical output.  
* Lightweight and runs entirely in the console.  
  

**Tech Stack**  
* C++ – core logic and execution  
* STL – string handling and randomization  
  

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

**Video Demo**  
[Video Demo for C++ Anagram Generator](https://youtu.be/DWqceeH8hds)  

  
**Data Source**  
My file words.csv is based on [eng_41320.csv](https://gist.github.com/diplodata/be26123b3f45a7ffab36426da2d2ee1f) 


**How to Run**  
1. Clone this repository:  
   ```bash
   git clone https://github.com/yourusername/cpp-anagram-generator.git
   cd cpp-anagram-generator
2. Compile the program:
   g++ anagram.cpp -o anagram
3. Run the executable:
   ./anagram
  

**Compatibility Notes**  
This C++ anagram generator has been tested in the following environments:  
  
* OneCompiler.com ✅  
-- Compiles and runs correctly  
  
* OnlineGDB.com ⚠️  
-- File access to 'words.csv' may not be supported; tries to compile the csv file  
  
Recommendation: Use OneCompiler or a local compiler (C++14 or later) for best results.  

**License**  
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.  
