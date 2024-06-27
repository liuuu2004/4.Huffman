/**
 * Define a Huffman Tree
*/

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
    // root node of the Huffman tree
    std::shared_ptr<TreeNode> root_;
    
    /**
     * @brief convert a Huffman-encoded string to its original sequence
     * @param s :Huffman-encoded string tobe converted
    */
    std::vector<char> to_byte_array(std::string &s);

    /**
     * @brief Huffman Tree Constructor, build a Huffman tree from the given mapping from char to str
     * @param code :a mapping from char to string(binary)
    */
    HuffmanTree(std::unordered_map<char, std::string> &code);

    /**
     * @brief Huffman Tree Constructor, build a Huffman tree from a given mapping from char to int
     * @param byte_cnt :a mapping from char to its frequencies
    */
    HuffmanTree(std::unordered_map<char, int> &byte_cnt);

    /**
     * @brief convert a Huffman tree to a mapping from char to str
     * @return mapping from char to str decoded from a Huffman tree
    */
    std::unordered_map<char, std::string> to_huffman_code();

private:
    /**
     * @brief recursive build a mapping from char to str from a Hufman tree
     * @param code :encoded map from char to str
     * @param node :Huffman tree node used to build a map
     * @param s :string to store the Huffman code of a char
    */
    void dfs(std::unordered_map<char, std::string> &code, std::shared_ptr<TreeNode> node, std::string s);

    /**
     * @brief merge two nodes and let the merged node be their parent
     * @param node1 :node to be merged
     * @param node2 :node to be merged
    */
    std::shared_ptr<TreeNode> join(std::shared_ptr<TreeNode> node1, std::shared_ptr<TreeNode> node2);
};

#endif