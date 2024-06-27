#include "data_manager.h"
#include "huffman_tree.h"

void DataManager::compress(const std::string &file_before, const std::string &file_after) {
    FileManager fm;
    auto ori_content = fm.read_file(file_before);
    std::unordered_map<char, int> res;
    for (auto c : ori_content) {
        res[c]++;
    }
    HuffmanTree ht(res);
    auto coded_map = ht.to_huffman_code();
    
}

int DataManager::encode(std::unordered_map<char, std::string> &huffman_map, std::vector<char> &res,
                        std::vector<char> &buffer) {
    res.clear();
    int total_bit_cnt = 0;
    char byte = 0;
    int bit_cnt = 0;
    for (auto c : buffer) {
        for (unsigned i = 0; i < huffman_map[c].length(); i++) {
            char bit = huffman_map[c][i] == '0' ? 0 : 1;
            byte <<= 1;
            byte |= bit;
            ++bit_cnt;
            ++total_bit_cnt;
            if (bit_cnt == 8) {
                res.emplace_back(byte);
                byte = 0;
                bit_cnt = 0;
            }
        }
    }
    if (bit_cnt) {
        while (bit_cnt < 8) {
            byte <<= 1;
            ++bit_cnt;
        }
        res.emplace_back(byte);
    }
    return total_bit_cnt;
}