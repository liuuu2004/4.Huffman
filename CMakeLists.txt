cmake_minimum_required(VERSION 3.10)
project(HuffmanCompressor)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

# 添加库
add_library(min_heap src/min_heap.cpp)
add_library(tree_node src/tree_node.cpp)
add_library(huffman_tree src/huffman_tree.cpp)
add_library(file_manager src/file_manager.cpp)
add_library(data_manager src/data_manager.cpp)
add_library(cmd_helper src/cmd_helper.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 添加测试可执行文件
add_executable(min_heap_test test/min_heap_test.cpp)
add_executable(huffman_tree_test test/huffman_tree_test.cpp)
add_executable(file_manager_test test/file_manager_test.cpp)
add_executable(data_manager_test test/data_manager_test.cpp)

# 添加主程序可执行文件
add_executable(huffman_compressor src/main.cpp)

# 链接库到测试可执行文件
target_link_libraries(min_heap_test tree_node min_heap ${GTEST_LIBRARIES} pthread)
target_link_libraries(huffman_tree_test huffman_tree tree_node min_heap ${GTEST_LIBRARIES} pthread)
target_link_libraries(file_manager_test file_manager ${GTEST_LIBRARIES} pthread)
target_link_libraries(data_manager_test data_manager huffman_tree tree_node min_heap ${GTEST_LIBRARIES} pthread)

# 链接库到主程序可执行文件
target_link_libraries(huffman_compressor cmd_helper data_manager file_manager huffman_tree tree_node min_heap pthread)

enable_testing()
add_test(NAME min_heap_test COMMAND min_heap_test)
add_test(NAME huffman_tree_test COMMAND huffman_tree_test)
add_test(NAME file_manager_test COMMAND file_manager_test)
add_test(NAME data_manager_test COMMAND data_manager_test)