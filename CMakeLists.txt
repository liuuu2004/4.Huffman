cmake_minimum_required(VERSION 3.10)
project(HuffmanCompressor)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_library(min_heap src/min_heap.cpp)
add_library(tree_node src/tree_node.cpp)
add_library(huffman_tree src/huffman_tree.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(min_heap_test test/min_heap_test.cpp)
add_executable(huffman_tree_test test/huffman_tree_test.cpp)

target_link_libraries(min_heap_test tree_node min_heap ${GTEST_LIBRARIES} pthread)
target_link_libraries(huffman_tree_test huffman_tree tree_node min_heap ${GTEST_LIBRARIES} pthread)

enable_testing()
add_test(NAME min_heap_test COMMAND min_heap_test)
add_test(NAME huffman_tree_test COMMAND huffman_tree_test)
