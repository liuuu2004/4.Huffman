#ifndef HUFFMAN_TREE_H_
#define HUFFMAN_TREE_H_

#include "min_heap.h"
#include "tree_node.h"
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class HuffmanTree {
public:
    std::shared_ptr<TreeNode> root_;
    
    std::vector<char> to_byte_array(std::string &s);
    HuffmanTree(std::unordered_map<char, std::string> &code);
    HuffmanTree(std::unordered_map<char, int> &byte_cnt);
    ~HuffmanTree();
    std::unordered_map<char, std::string> to_huffman_code();

private:
    void dfs(std::unordered_map<char, std::string> &mp, std::shared_ptr<TreeNode> node, std::string s);
    std::shared_ptr<TreeNode> join(std::shared_ptr<TreeNode> node1, std::shared_ptr<TreeNode> node2);
};

#endif