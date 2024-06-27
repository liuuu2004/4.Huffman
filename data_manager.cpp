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
    ht.to_huffman_code();
    
}