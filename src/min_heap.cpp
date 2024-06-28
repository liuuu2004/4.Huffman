#include "min_heap.h"
#include "tree_node.h"
// #include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>

int MinHeap::size() {
    return heap_.size();
}

void MinHeap::minimize_heap(int i) {
    int left = (i << 1) + 1;
    int right = (i << 1) + 2;
    int smallest = i;

    if (left < heap_.size() && heap_[left]->frequency_ < heap_[smallest]->frequency_) {
        smallest = left;
    }
    if (right < heap_.size() && heap_[right]->frequency_ < heap_[smallest]->frequency_) {
        smallest = right;
    }
    if (smallest != i) {
        std::swap(heap_[i], heap_[smallest]);
        minimize_heap(smallest);
    }
}

void MinHeap::maintain_heap(int i) {
    if (i <= 0) {
        return;
    }
    int p = (i - 1) >> 1;
    if (i > 0 && heap_[p]->frequency_ > heap_[i]->frequency_) {
        std::swap(heap_[i], heap_[p]);
        maintain_heap(p);
    }
}

void MinHeap::push(std::shared_ptr<TreeNode> node) {
    heap_.emplace_back(node);
    maintain_heap(heap_.size() - 1);
}

std::shared_ptr<TreeNode> MinHeap::pop() {
    if (heap_.size() == 0) {
        throw std::out_of_range("empty heap");
    }
    auto res = heap_[0];
    heap_[0] = heap_.back();
    heap_.pop_back();
    minimize_heap(0);
    return res;
}