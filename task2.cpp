#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

int main() {
    std::ifstream logfile("log.txt");
    std::ofstream summary("summary.txt");
    std::ofstream error("error.txt");

    if (!logfile)  { std::cerr<<"Cannot open log.txt\n";   return 1; }
    if (!summary)  { std::cerr<<"Cannot open summary.txt\n"; return 1; }
    if (!error)    { std::cerr<<"Cannot open error.txt\n";   return 1; }
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

    summary << "INFO: " << info << "\n"
            << "ERROR: " << err << "\n"
            << "WARNING: " << warning << "\n";

    logfile.close();
    summary.close();
    error.close();
    return 0;
     
}
