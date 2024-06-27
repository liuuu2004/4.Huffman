#include "cmd_helper.h"
#include "data_manager.h"
#include "file_manager.h"
#include <iostream>
#include <vector>

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
            std::string input_file, output_file;
            std::cin >> input_file >> output_file;
            compress(input_file, output_file);
        } else if (command == "-dc") {
            // -decompress
            std::string input_file, output_file;
            std::cin >> input_file >> output_file;
            decompress(input_file, output_file);
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

void CMDHelper::compress(const std::string &file_before, const std::string &file_after) {
    FileManager fm;
    std::string tobe_encoded = fm.read_file(file_before);
    auto cnt_map = count_each_byte(tobe_encoded);
    encoded_map = get_huff_code(cnt_map);
    std::vector<char> res;
    total_bit_cnt = encode(res, encoded_map, tobe_encoded);
    std::string s(res.begin(), res.end());
    fm.write_file(file_after, s);
}

void CMDHelper::decompress(const std::string &file_after, const std::string &file_output) {
    FileManager fm;
    std::string tobe_decoded = fm.read_file(file_after);
    std::string encoded_str = decode(tobe_decoded, total_bit_cnt);
    auto original_data = decompress_manager(encoded_str, encoded_map);
    std::string s(original_data.begin(), original_data.end());
    fm.write_file(file_output, s);
}