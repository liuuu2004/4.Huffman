#include "huffman_tree.h"
#include "min_heap.h"
#include "tree_node.h"
#include <cstdio>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<char> HuffmanTree::to_byte_array(std::string &s) {
    // printf("\n%s\n", s.c_str());
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
        std::string str = it.second;
        auto now_node = root_;
        for (unsigned i = 0; i < str.size(); ++i) {
            if (str[i] == '0') {
                if (!now_node->left_) {
                    now_node->left_ = std::make_shared<TreeNode>(it.first, 0);
                }
                now_node = now_node->left_;
            } else {
                if (!now_node->right_) {
                    now_node->right_ = std::make_shared<TreeNode>(it.first, 0);
                }
                now_node = now_node->right_;
            }
        }
    }
}

HuffmanTree::HuffmanTree(std::unordered_map<char, int> &byte_cnt) {
    std::shared_ptr<MinHeap> pq = std::make_shared<MinHeap>();

    for (auto &i : byte_cnt) {
        std::shared_ptr<TreeNode> new_node = std::make_shared<TreeNode>(i.first, i.second);
        pq->push(new_node);
    }

    // printf("\nInitial PQ Size: %d\n", pq->size());

    while (pq->size() > 1) {
        auto first = pq->pop();
        auto second = pq->pop();

        // printf("\nPopped nodes: %c(%d), %c(%d)\n", first->data_, first->frequency_, second->data_, second->frequency_);

        std::shared_ptr<TreeNode> new_node = std::make_shared<TreeNode>('$', first->frequency_ + second->frequency_);
        new_node->left_ = first;
        new_node->right_ = second;

        // printf("\nCreated new node %c with frequency: %d\n", new_node->data_, new_node->frequency_);

        pq->push(new_node);
    }
    root_ = pq->pop();

    // if (root_->left_ == nullptr && root_->right_ == nullptr) {
    //     printf("\nLRNULL\n");
    // }
}

std::unordered_map<char, std::string> HuffmanTree::to_huffman_code() {
    std::unordered_map<char, std::string> res;
    dfs(res, root_, "");
    
    // printf("\nFINISH HUFFMAN CODE\n");

    return res;
}

void HuffmanTree::dfs(std::unordered_map<char, std::string> &code, std::shared_ptr<TreeNode> &node, std::string s) {
    // printf("\nDFS\n");

    if (node->left_ == nullptr && node->right_ == nullptr) {
        // printf("\nALLEMPTY\n");

        if (node == root_) {
            // printf("\nISROOT\n");
            // printf("%d\n", node->data_);
            code[node->data_] = "0";
            // printf("\nDONE\n");
        } else {
            code[node->data_] = s;
        }
        return;
    }
    if (node->left_ != nullptr) {
        // printf("\nTOLEFT\n");
        dfs(code, node->left_, s + "0");
    }
    if (node->right_ != nullptr) {
        // printf("\nTORIGHT\n");
        dfs(code, node->right_, s + "1");
    }
}

void HuffmanTree::join(std::shared_ptr<TreeNode> &root, std::shared_ptr<TreeNode> &node1, std::shared_ptr<TreeNode> &node2) {
    root->left_ = node1;
    root->right_ = node2;
}