/**
 * 
*/

#ifndef DATA_MANAGER_H_
#define DATA_MANAGER_H_

#include "huffman_tree.h"
#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<char, int> count_each_byte(const std::string &buffer);
std::unordered_map<char, std::string> get_huff_code(std::unordered_map<char, int> &byte_cnt);
int encode(std::vector<char> &res, std::unordered_map<char, std::string> &encoded, std::string &buffer);
std::string decode(const std::string &buffer, int bit_cnt);
std::vector<char> decompress_manager(std::string &huffman_str, std::unordered_map<char, std::string> encoded);  

#endif