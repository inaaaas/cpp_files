
#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_set>
#include <string>

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
    std::ifstream input("input2.txt");
    std::ofstream output("output2.txt");
    if (!input.is_open()) {
        std::cerr << "input2.txt file open fail" << std::endl;
        return 1;
    }
    if (!output.is_open()) {
        std::cerr << "output2.txt file open fail" << std::endl;
        return 1;
    }

    std::unordered_set <std::string> words;
    std::string oneWord;
    while (input >> oneWord) {
        std::string noPunctWord = cleanPunct(oneWord);

        if (words.find(noPunctWord) != words.end()) {   // words.count(noPunctWord)
            output << " * ";
        }
        else {
            output << oneWord << " ";
            words.insert(noPunctWord);
        }
    }
    input.close();
    output.close();
    return 0;
}