#include "tree_node.h"

TreeNode::TreeNode(int data, int frequency) : data_(data), frequency_(frequency) {
    this->left_ = nullptr;
    this->right_ = nullptr;
}