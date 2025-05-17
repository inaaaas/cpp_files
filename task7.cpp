// 7. Simple CSV to JSON Converter
// Objective: Convert a small .csv file into a .json file manually (without using libraries).
// Input CSV example:
// name,age
// Alice,23
// Bob,30
// Output JSON:
// [
//   {"name": "Alice", "age": 23},
//   {"name": "Bob", "age": 30}
// ]

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::ifstream infile("input7.csv");
    std::ofstream outfile("output7.json");
    if (!infile.is_open()) {
        std::cerr << "input7.csv file open fail" << std::endl;
        return 1;
    }
    if (!outfile.is_open()) {
        std::cerr << "output7.json file open fail" << std::endl;
        return 1;
    }  

    std::string line;
    std::vector<std::string> headers;

    if (std::getline(infile, line)) {
        std::stringstream str(line);
        std::string header;
        while (std::getline(str, header, ',')) {
            headers.push_back(header);
        }
    }

    outfile <<"[\n";
    bool first = true;
     while (std::getline(infile, line)) {
        if (!first) {
            outfile << ",\n";
        }
        first = false;

        std::stringstream ss(line);
        std::string field;
        std::vector<std::string> fields;

        while (std::getline(ss, field, ',')) {
            fields.push_back(field);
        }

        outfile << "  {\n";
        for (size_t i = 0; i < headers.size(); ++i) {
            outfile << "    \"" << headers[i] << "\": ";
            bool isNumber = true;
            for (char c : fields[i]) {
                if (!isdigit(c)) {
                    isNumber = false;
                    break;
                }
            }
            if (isNumber)
                outfile << fields[i];
            else
                outfile << "\"" << fields[i] << "\"";

            if (i != headers.size() - 1)
                outfile << ",";
            outfile << "\n";
        }
        outfile << "  }";
    }

    outfile << "\n]\n";

    infile.close();
    outfile.close();
    return 0;
}