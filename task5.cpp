// 5. Big Numbers Summator
// Objective: Sum very large integers that cannot fit into built-in types.
// Input file has huge numbers, one per line.
// Output the sum of all numbers.
// (No BigInt libraries, manually simulate addition digit by digit.)
// Skills practiced: streams, parsing large inputs, algorithmic thinking.
#include <iostream>
#include <fstream>
#include <string>

std::string sumBig(const std::string first, const std::string second) {
    std::string res;
    int i = first.size() - 1;
    int j = second.size() - 1;
    int carry= 0;
    while (i >= 0 || j >= 0 || carry > 0) {
        int a;
        int b;
        if (i >= 0) {
            a = first[i] - '0';
            i--;
        }
        else {
            a = 0;
        }
        
        if (j >= 0) {
            b = second[j] - '0';
            j--;
        }
        else {
            b = 0;
        }
        int sum = a + b + carry;
        carry = sum / 10;
        char sum2 = '0' + (sum % 10);
        res.push_back(sum2);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    std::ifstream input("input5.txt");
    std::ofstream output("output5.txt");
    if (!input.is_open()) {
        std::cerr << "input5.cpp file open fail" << std::endl;
        return 1;
    }
    if (!output.is_open()) {
        std::cerr << "output5.cpp file open fail" << std::endl;
        return 1;
    }
    std::string line;
    std::string sum = "0";

    while (std::getline(input, line)) {
       if (!line.empty()) {
            sum = sumBig(sum, line);
       }
    }
    output << sum << "\n";
    return 0;
    
}