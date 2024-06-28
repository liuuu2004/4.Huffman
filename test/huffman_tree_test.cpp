#include <cstdio>
#include <gtest/gtest.h>
#include <string>
#include <unordered_map>
#include <vector>
#include "../src/huffman_tree.h"

TEST(HuffmanTreeTest, ToByteArrayTest) {
    std::unordered_map<char, int> byte_cnt = {{'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}};
    HuffmanTree ht(byte_cnt);

    printf("\nTEST\n");

    std::unordered_map<char, std::string> huffman_code = ht.to_huffman_code();
    std::string encoded_string;
    for (const auto& [ch, code] : huffman_code) {
        encoded_string += code;
    }

    printf("\nTEST\n");

    std::vector<char> decoded_string = ht.to_byte_array(encoded_string);

    printf("\nTEST\n");

    std::string decoded_result(decoded_string.begin(), decoded_string.end());

    for (auto& ch : decoded_result) {
        EXPECT_NE(byte_cnt.find(ch), byte_cnt.end());
    }
}

TEST(HuffmanTreeTest, ToHuffmanCodeTest) {
    std::unordered_map<char, int> byte_cnt = {{'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}};
    HuffmanTree huffman_tree(byte_cnt);

    std::unordered_map<char, std::string> huffman_code = huffman_tree.to_huffman_code();

    EXPECT_EQ(huffman_code.size(), byte_cnt.size());
    for (const auto& [ch, code] : huffman_code) {
        EXPECT_NE(byte_cnt.find(ch), byte_cnt.end());
        EXPECT_FALSE(code.empty());
    }
}

TEST(HuffmanTreeTest, ConstructWithCodeTest) {
    std::unordered_map<char, std::string> code = {{'a', "00"}, {'b', "01"}, {'c', "100"}, {'d', "101"}, {'e', "110"}, {'f', "111"}};
    HuffmanTree huffman_tree(code);

    std::unordered_map<char, std::string> huffman_code = huffman_tree.to_huffman_code();

    EXPECT_EQ(huffman_code.size(), code.size());
    for (const auto& [ch, generated_code] : huffman_code) {
        EXPECT_EQ(generated_code, code[ch]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
