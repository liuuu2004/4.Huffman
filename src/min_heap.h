/**
 * Define a MinHeap to Build a Priority Queue to Build a Huffman Tree
*/


#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_

#include "tree_node.h"
#include <memory>
#include <vector>

class MinHeap {
public:
    MinHeap() = default;

    /**
     * @brief push a tree node to the heap
     * @param node :tree node to be pushed
    */
    void push(std::shared_ptr<TreeNode> node);

    /**
     * @brief pop the tree node with minimum value
     * @return ptr to the tree node with minimum value
    */
    std::shared_ptr<TreeNode> pop();

    /**
     * @brief get the size of the min heap
     * @return size of the min heap
    */
    int size();

private:
    // size of the min heap
    int size_ = 0;

    // vector to store the data of the min heap
    std::vector<std::shared_ptr<TreeNode>> heap_;

    /**
     * @brief keep the min heap balanced after deletion
     * @param i :psoition to be adjusted
    */
    void minimize_heap(int i);

    /**
     * @brief keep the min heap balanced after insertion
     * @param i :position to be adjusted
    */
    void maintain_heap(int i);
};

#endif
