#include "huffman_tree.h"
#include "min_heap.h"
#include "tree_node.h"
#include <memory>
#include <string>
#include <unordered_map>
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

HuffmanTree::HuffmanTree(std::unordered_map<char, int> &byte_cnt) {
    auto pq = std::make_shared<MinHeap>();

    for (auto i : byte_cnt) {
        auto new_node = std::make_shared<TreeNode>(i.first, i.second);
        pq->push(new_node);
    }
    while (pq->size() > 1) {
        auto first = pq->pop();
        auto second = pq->pop();
        auto new_node = join(first, second);
        pq->push(new_node);
    }
    root_ = pq->pop();
}

std::unordered_map<char, std::string> HuffmanTree::to_huffman_code() {
    std::unordered_map<char, std::string> res;
    dfs(res, root_, "");
    return res;
}

void HuffmanTree::dfs(std::unordered_map<char, std::string> &code, std::shared_ptr<TreeNode> node, std::string s) {
    if (node->left_ == nullptr && node->right_ == nullptr) {
        if (node == root_) {
            code[node->data_] = "0";
        } else {
            code[node->data_] = s;
        }
        return;
    }
    if (node->left_ != nullptr) {
        dfs(code, node->left_, s + "0");
    }
    if (node->right_ != nullptr) {
        dfs(code, node->right_, s + "1");
    }
}

std::shared_ptr<TreeNode> HuffmanTree::join(std::shared_ptr<TreeNode> node1, std::shared_ptr<TreeNode> node2) {
    auto res = std::make_shared<TreeNode>(0, node1->frequency_ + node2->frequency_);
    res->left_ = node1;
    res->right_ = node2;
    return res;
}