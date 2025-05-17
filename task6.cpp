// 6. Word Occurrence Counter
// Objective: Count how many times each word appears in a text file.
// Ignore case (treat "Apple" and "apple" as the same).
// Output the result sorted alphabetically or by frequency.
// Skills practiced: parsing, ifstream, maps, thinking about efficient file reading.

#include <iostream>
#include <fstream>
#include <string>
#include <map>

std::string cleanPunct(const std::string& word) {
    std::string cleaned;
    for (char c : word) {
        if (isalpha(c)) {
            cleaned += std::tolower(c);
        }
    }
    return cleaned;
}
int main() {
    std::ifstream infile("input6.txt");
    std::ofstream outfile("output6.txt");
    if (!infile.is_open()) {
        std::cerr << "input6.cpp file open fail" << std::endl;
        return 1;
    }
    if (!outfile.is_open()) {
        std::cerr << "output6.cpp file open fail" << std::endl;
        return 1;
    }  
    std::map<std::string, int> words;
    std::string word;
    
    while (infile >> word) {
        std::string noPunctWord = cleanPunct(word);
        auto it = words.find(noPunctWord);
        if (it != words.end()) {
            it->second++;
        }
        else {
            words.insert({noPunctWord, 1});
        }
    }
    for (auto& it : words) {
        outfile << it.first << ": " << it.second << "\n";
    }
    infile.close();
    outfile.close();
    return 0;
}
