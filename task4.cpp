// 4. Simple Stream Encryption
// Objective: Create a simple cipher that shifts every letter by +1 (Caesar cipher).
// Read a file.
// Encrypt: a becomes b, z becomes a, A becomes B, etc.
// Write the encrypted text to another file.
// (Optional) Allow decryption too.
// Skills practiced: character processing, ifstream, ofstream, handling ASCII.

#include <iostream>
#include <sstream>
#include <fstream>

void encrypt (std::ifstream& input, std::ofstream& output) {
    char ch;
    while (input.get(ch)) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            int offset = (ch - base + 1) % 26;  
            ch = base + offset;
        }
        output.put(ch);
    }
}

void decrypt (std::ifstream& input, std::ofstream& output) {
    char ch;
    while(input.get(ch)) {
        if (isalpha(ch)) {
            char base = (isupper(ch)) ? 'A' : 'a';
            int offset = (ch - base + 25) % 26;
            ch = base + offset;
        }
        output.put(ch);
    }
}
int main() {
    
    std::ifstream input("output3.txt");
    std::ofstream output("output4.txt");
    if (!input.is_open()) {
        std::cerr << "output3.txt file open fail" << std::endl;
        return 1;
    }
    if (!output.is_open()) {
        std::cerr << "output4.txt file open fail" << std::endl;
        return 1;
    }

    std::cout << " Do you want encrypt or decrypt the text ? \n1. encrypt\n2. decrypt" << std::endl;
    int choice = 0;
    std::cin >> choice;
    if (choice == 1) {
        encrypt(input, output);
    }
    else if (choice == 2) {
        decrypt(input, output);
    }

    input.close();
    output.close();
    return 0;
}
