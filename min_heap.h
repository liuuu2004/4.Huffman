#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_

#include "tree_node.h"
#include <memory>
#include <vector>

class MinHeap {
public:
    void push(std::shared_ptr<TreeNode> node);
    std::shared_ptr<TreeNode> pop();
    const int size() const ;

private:
    int size_ = 0;
    std::vector<std::shared_ptr<TreeNode>> heap_;

    void minimize_heap(int i);
    void maintain_heap(int i);
};

#endif
