#include "cmd_helper.h"
#include "file_manager.h"
#include <cstdio>
#include <fstream>


void CMDHelper::run() {
    std::string command;
    while (true) {
        std::cout << "HuffmanCompressor> ";
        std::cin >> command;
        if (command == "-h") {
            // -helper
            show_helper();
        } else if (command == "-ec") {
            // -compress
            std::string input_file, output_file;
            input_file = "before_compression.txt";
            output_file = "after_compression.txt";
            compress(input_file, output_file);
        } else if (command == "-dc") {
            // -decompress
            std::string input_file, output_file;
            input_file = "after_compression.txt";
            output_file = "after_decompression.txt";
            decompress(input_file, output_file);
        } else if (command == "-a") {
            // -analyze
            analyze_dec();
        } else if (command == "-ra") {
            // -reverse-analyze
            analyze_inc();
        } else if (command == "-ls") {
            // -list
            std::string input_file, output_file, final_file;
            input_file = "before_compression.txt";
            output_file = "after_compression.txt";
            final_file = "after_decompression.txt";
            show_both(input_file, output_file, final_file);
        } else if (command == "-pf") {
            // -performance

        } else if (command == "-q") {
            // -quit
            break;
        } else {
            // exception
            printf("Inlegal command, please try again or type -h to seek for help;\n");
        }
    }
}

void CMDHelper::show_helper() {
    std::cout << "\tyou can press:\n";
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

    std::ifstream check_file_before(file_before);
    if (!check_file_before.good()) {
        std::ofstream create_file_before(file_before);
        create_file_before << "Sample text input if file does not exist.";
        create_file_before.close();
    }
    check_file_before.close();

    std::ifstream check_file_after(file_before);
    if (!check_file_after.good()) {
        std::ofstream create_file_after(file_before);
        create_file_after.close();
    }
    check_file_after.close();

    std::ofstream clear_file_after(file_after, std::ofstream::out | std::ofstream::trunc);
    clear_file_after.close();

    std::string tobe_encoded = fm.read_file(file_before);
    cnt_map = count_each_byte(tobe_encoded);
    encoded_map = get_huff_code(cnt_map);
    std::vector<char> res;
    total_bit_cnt = encode(res, encoded_map, tobe_encoded);
    std::string s(res.begin(), res.end());
    fm.write_file(file_after, s);
}

void CMDHelper::decompress(const std::string &file_after, const std::string &file_output) {
    FileManager fm;

    std::ifstream check_file_after(file_after);
    if (!check_file_after.good()) {
        printf("error: file %s does not exist.\n", file_after.c_str());
        check_file_after.close();
        return;
    }
    check_file_after.close();

    std::ofstream clear_file_output(file_output, std::ofstream::out | std::ofstream::trunc);
    clear_file_output.close();

    std::string tobe_decoded = fm.read_file(file_after);
    std::string encoded_str = decode(tobe_decoded, total_bit_cnt);
    auto original_data = decompress_manager(encoded_str, encoded_map);
    std::string s(original_data.begin(), original_data.end());
    fm.write_file(file_output, s);
}

void CMDHelper::analyze_dec() {
    // character, character-hexcode, compressed-character-binary, frequency, percentage
    struct Data {
        char ch;
        std::string binary;
        int frequency;
        double percentage;
    };
    std::vector<Data> res;
    for (auto c : cnt_map) {
        Data data;
        data.ch = c.first;
        data.binary = encoded_map.at(c.first);
        data.frequency = c.second;
        data.percentage = total_bit_cnt / (double)c.second / 8.0;

        res.emplace_back(data);
    }
    std::sort(res.begin(), res.end(), [](Data a, Data b) {
        return a.frequency > b.frequency; });
    printf("\n");
    for (auto d : res) {
        printf("\t%c %x %6s %4d %.5lf\n", d.ch, d.ch, d.binary.c_str(), d.frequency, d.percentage);
    }
}

void CMDHelper::analyze_inc() {
    // character, character-hexcode, compressed-character-binary, frequency, percentage
    struct Data {
        char ch;
        std::string binary;
        int frequency;
        double percentage;
    };
    std::vector<Data> res;
    for (auto c : cnt_map) {
        Data data;
        data.ch = c.first;
        data.binary = encoded_map.at(c.first);
        data.frequency = c.second;
        data.percentage = total_bit_cnt / (double)c.second / 8.0;

        res.emplace_back(data);
    }
    std::sort(res.begin(), res.end(), [](Data a, Data b) {
        return a.frequency < b.frequency; });
    printf("\n");
    for (auto d : res) {
        printf("\t%c %x %6s %4d %.5lf\n", d.ch, d.ch, d.binary.c_str(), d.frequency, d.percentage);
    }
}

void CMDHelper::show_both(const std::string &file_before, const std::string &file_after,
                          const std::string &file_final) {
    FileManager fm;
    auto s1 = fm.read_file(file_before);
    printf("\n%s:\n%s\n\n", file_before.c_str(), s1.c_str());
    
    auto s2 = fm.read_file(file_after);
    printf("%s:\n%s\n\n", file_after.c_str(), s2.c_str());

    auto s3 = fm.read_file(file_final);
    printf("%s:\n%s\n\n", file_final.c_str(), s3.c_str());
}

