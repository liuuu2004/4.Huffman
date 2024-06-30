#include "data_manager.h"
#include "huffman_tree.h"
#include <unordered_map>
#include <vector>

std::unordered_map<char, int> count_each_byte(const std::string &buffer) {
    std::unordered_map<char, int> res;
    for (auto c : buffer) {
        res[c]++;
    }
    return res;
}

std::unordered_map<char, std::string> get_huff_code(std::unordered_map<char, int> &byte_cnt) {
    HuffmanTree ht(byte_cnt);
    auto res = ht.to_huffman_code();
    return res;
}

int encode(std::vector<char> &res, std::unordered_map<char, std::string> &encoded, std::string &buffer) {
    res.clear();
    int total_bit_cnt = 0;
    char byte = 0;
    int bit_cnt = 0;
    for (auto c : buffer) {
        for (auto bit_char : encoded[c]) {
            char bit = bit_char == '0' ? 0 : 1;
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
        byte <<= (8 - bit_cnt);
        res.emplace_back(byte);
    }
    return total_bit_cnt;
}

std::string decode(const std::string &buffer, int bit_cnt) {
    std::string res;
    int total_bits_processed = 0;
    for (auto c : buffer) {
        for (int j = 7; j >= 0; --j) {
            if (total_bits_processed == bit_cnt) {
                break;
            }
            if (c >> j & 1) {
                res += "1";
            } else {
                res += "0";
            }
            ++total_bits_processed;
        }
    }
    return res;
}

std::vector<char> decompress_manager(std::string &huffman_str, std::unordered_map<char, std::string> encoded) {
    HuffmanTree ht(encoded);
    auto res = ht.to_byte_array(huffman_str);
    return res;
}