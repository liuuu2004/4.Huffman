/**
 * Define TreeNode Class to Build a Huffman Tree.
*/


#ifndef TREE_NODE_H_
#define TREE_NODE_H_

#include <memory>
class TreeNode {
public:
    /**
     * data_ : data stored in this tree node
     * frequency_ : times data in the .txt file
    */
    int data_, frequency_;

    /**
     * left & right node of the tree node
    */
    std::shared_ptr<TreeNode> left_, right_;

    /**
     * @brief create a tree node
     * @param data :data stored in this tree ndoe
     * @param frequency :times data occurred in the .txt file
    */
    TreeNode(int data, int frequency);
};

#endif