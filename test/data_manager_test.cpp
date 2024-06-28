#include "../src/data_manager.h"
#include <gtest/gtest.h>
#include <unordered_map>
#include <string>
#include <vector>

// 测试 count_each_byte 函数
TEST(DataManagerTest, CountEachByte) {
    std::string test_str = "hello world";
    std::unordered_map<char, int> byte_count = count_each_byte(test_str);
    EXPECT_EQ(byte_count['h'], 1);
    EXPECT_EQ(byte_count['e'], 1);
    EXPECT_EQ(byte_count['l'], 3);
    EXPECT_EQ(byte_count['o'], 2);
    EXPECT_EQ(byte_count[' '], 1);
    EXPECT_EQ(byte_count['w'], 1);
    EXPECT_EQ(byte_count['r'], 1);
    EXPECT_EQ(byte_count['d'], 1);
}

// 测试 get_huff_code 函数
TEST(DataManagerTest, GetHuffCode) {
    std::unordered_map<char, int> byte_count = { {'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45} };
    std::unordered_map<char, std::string> huff_code = get_huff_code(byte_count);
    EXPECT_GT(huff_code.size(), 0);
}

// 测试 encode 函数
TEST(DataManagerTest, Encode) {
    std::unordered_map<char, std::string> encoded = { {'a', "0"}, {'b', "101"}, {'c', "100"}, {'d', "111"}, {'e', "1101"}, {'f', "1100"} };
    std::string buffer = "abcdef";
    std::vector<char> res;
    int total_bits = encode(res, encoded, buffer);
    EXPECT_GT(total_bits, 0);
    EXPECT_GT(res.size(), 0);
}

// 测试 decode 函数
TEST(DataManagerTest, Decode) {
    std::string buffer = "\xA2\xA4";
    int bit_cnt = 16;
    std::string decoded = decode(buffer, bit_cnt);
    EXPECT_EQ(decoded, "1010001010100100");
}

// 测试 decompress_manager 函数
TEST(DataManagerTest, DecompressManager) {
    std::string huffman_str = "1010100100";
    std::unordered_map<char, std::string> encoded = { {'a', "0"}, {'b', "101"}, {'c', "100"}, {'d', "111"}, {'e', "1101"}, {'f', "1100"} };
    std::vector<char> res = decompress_manager(huffman_str, encoded);
    EXPECT_GT(res.size(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
