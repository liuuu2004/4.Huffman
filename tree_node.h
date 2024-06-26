#ifndef TREE_NODE_H_
#define TREE_NODE_H_

#include <memory>
class TreeNode {
public:
    int data_, frequency_;
    std::shared_ptr<TreeNode> left_, right_;
    TreeNode(int data, int frequency);
};

#endif