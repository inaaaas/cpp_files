#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>


struct Student{
    std::string name;
    double grade;
};

int main() {
    std::ifstream file_read("input.csv");
    std::ofstream file_write("output.txt");

    if (!file_read)  std::cerr<<"Cannot open input.csv\n",  return 1;
    if (!file_write) std::cerr<<"Cannot open output.txt\n", return 1;

    //std::string word;
    // file_read >> word;

    std::string header;
    std::getline(file_read, header);
    
    
    std::vector<Student> students;

    std::string line;
    while (std::getline(file_read, line)) {
        if (line.empty()) {
            continue;
        }
        std::stringstream str(line);

        std::string name, mid, final, hw;

        if (!getline(str, name, ',')) {
            continue;
        }

        getline(str, mid, ',');
        getline(str, final, ',');
        getline(str, hw);

        
        double finalGrade = 0.3 * stod(mid) + 0.3 * stod(final) + 0.4 * stod(hw); 
        students.push_back({name, finalGrade});
    }

    std::sort(students.begin(), students.end(), [](auto& a, auto& b) { return a.grade > b.grade; });

    for (auto& s : students) {
         file_write << s.name << " : " << s.grade << "\n";
    }
}
