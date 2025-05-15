#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

int main() {
    std::ifstream logfile("log.txt");
    std::ofstream summary("summary.txt");
    std::ofstream error("error.txt");

    if (!logfile.is_open() || !summary.is_open() || !error.is_open()) {
        std::cerr << "File open fail" << std::endl;
        return 1;
    }
    std::string line;
    int info = 0, err = 0, warning = 0;

    while (std::getline(logfile, line)) {
        if (line.find("[INFO]") != std::string::npos) {
            info++;
        } 
        else if (line.find("[WARNING]") != std::string::npos) {
            warning++;
        }
        else if (line.find("[ERROR]") != std::string::npos) {
            err++;
            error << line << std::endl;
        }
    }

    summary << "INFO count: " << info << std::endl;
    summary << "ERROR count: " << err << std::endl;
    summary << "WARNING count: " << warning <<std::endl;

    logfile.close();
    summary.close();
    error.close();
    return 0;
     
}