#include "../src/file_manager.h"
#include <gtest/gtest.h>
#include <fstream>

class FileManagerTest : public ::testing::Test {
protected:
    FileManager fm;
    std::string test_file = "test.txt";
    std::string content = "Hello, World!";
    
    virtual void SetUp() {
        // 写入初始内容到文件中
        std::ofstream file(test_file);
        file << content;
        file.close();
    }

    virtual void TearDown() {
        // 删除测试文件
        remove(test_file.c_str());
    }
};

TEST_F(FileManagerTest, ReadFile) {
    std::string result = fm.read_file(test_file);
    EXPECT_EQ(result, content);
}

TEST_F(FileManagerTest, WriteFile) {
    std::string new_content = "New content";
    fm.write_file(test_file, new_content);
    std::string result = fm.read_file(test_file);
    EXPECT_EQ(result, new_content);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
