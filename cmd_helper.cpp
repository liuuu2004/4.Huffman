#include "cmd_helper.h"
#include <iostream>

void CMDHelper::run() {
    std::string command;
    while (true) {
        std::cout << "HuffmanCompressor > ";
        std::cin >> command;
        if (command == "-h") {
            // -helper
            show_helper();
        } else if (command == "-ec") {
            // -compress

        } else if (command == "-dc") {
            // -decompress

        } else if (command == "-a") {
            // -analyze

        } else if (command == "-ra") {
            // -reverse-analyze

        } else if (command == "-ls") {
            // -list

        } else if (command == "-pf") {
            // -performance

        } else if (command == "-q") {
            // -quit
            break;
        } else {
            // exception

        }
    }
}

void CMDHelper::show_helper() {
    std::cout << "\n\tyou can press:\n";
    std::cout << "\t  -ec to encode a file;\n";
    std::cout << "\t  -dc to decode a file;\n";
    std::cout << "\t  -a to analyze files;\n";
    std::cout << "\t  -ra to analyze files and print in reverse order;\n";
    std::cout << "\t  -ls to list files;\n";
    std::cout << "\t  -pf to show performance;\n";
    std::cout << "\t  -q to quit;\n";
}
