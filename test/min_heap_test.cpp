#include <cstdio>
#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include <algorithm>

#include "../src/min_heap.h"
#include "../src/tree_node.h"


TEST(MinHeapTest, PushPopTest) {
    auto heap = std::make_shared<MinHeap>();

    auto node1 = std::make_shared<TreeNode>(1, 5);
    auto node2 = std::make_shared<TreeNode>(2, 3);
    auto node3 = std::make_shared<TreeNode>(3, 8);
    auto node4 = std::make_shared<TreeNode>(4, 1);

    // std::cout << "TEST\n";

    heap->push(node1);
    // std::cout << "\nTEST\n";
    heap->push(node2);
    // std::cout << "\nTEST\n";
    heap->push(node3);
    heap->push(node4);
    // std::cout << "TEST\n";

    EXPECT_EQ(heap->size(), 4);
    // std::cout << "TEST\n";

    auto minNode = heap->pop();
    EXPECT_EQ(minNode->frequency_, 1);
    // std::cout << "TEST\n";

    EXPECT_EQ(heap->size(), 3);
    // std::cout << "TEST\n";

    minNode = heap->pop();
    EXPECT_EQ(minNode->frequency_, 3);
    // std::cout << "TEST\n";

    EXPECT_EQ(heap->size(), 2);
    // std::cout << "TEST\n";
}

TEST(MinHeapTest, SortTest) {
    auto heap = std::make_shared<MinHeap>();

    std::vector<int> nums = {3, 7, 4, 12, 8, 5, -3, 2, 6};
    for (int i = 0; i < nums.size(); ++i) {
        auto node = std::make_shared<TreeNode>(i, nums[i]);
        heap->push(node);
    }
    std::vector<int> res;
    while (heap->size() > 0) {
        res.emplace_back(heap->pop()->frequency_);
    }
    std::sort(nums.begin(), nums.end());
    EXPECT_EQ(res, nums);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}