#include "huffman_tree.h"
#include "tree_node.h"
#include <memory>
#include <vector>

std::vector<char> HuffmanTree::to_byte_array(std::string &s) {
    std::vector<char> res;
    auto now_node = root_;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0') {
            now_node = now_node->left_;
        } else {
            now_node = now_node->right_;
        }
        if (now_node->left_ == nullptr && now_node->right_ == nullptr) {
            res.emplace_back(now_node->data_);
            now_node = root_;
        }
    }
    return res;
}

HuffmanTree::HuffmanTree(std::unordered_map<char, std::string> &code) {
    root_ = std::make_shared<TreeNode>(0, 0);

    for (auto &&it : code) {
        auto str = it.second;
        auto now_node = root_;
        for (unsigned i = 0; i < str.size(); ++i) {
            if (str[i] == '0') {
                if (!now_node->left_) {
                    now_node->left_ = std::make_shared<TreeNode>(it.first, 0);
                }
            }
        }
    }
}