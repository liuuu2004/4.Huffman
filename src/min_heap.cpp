#include "min_heap.h"
#include "tree_node.h"
#include <iostream>
#include <memory>
#include <utility>

int MinHeap::size() {
    return size_;
}

void MinHeap::minimize_heap(int i) {
    int left = (i << 1) + 1;
    int right = (i << 1) + 2;
    int smallest = i;

    if (left <= size_ && heap_[left]->frequency_ < heap_[smallest]->frequency_) {
        smallest = left;
    }
    if (right <= size_ && heap_[right]->frequency_ < heap_[smallest]->frequency_) {
        smallest = right;
    }
    if (smallest != i) {
        std::swap(heap_[i], heap_[smallest]);
        minimize_heap(smallest);
    }
}

void MinHeap::maintain_heap(int i) {
    int p = (i >> 1);
    if (heap_[p]->frequency_ > heap_[i]->frequency_) {
        std::swap(heap_[i], heap_[p]);
        maintain_heap(p);
    }
}

void MinHeap::push(std::shared_ptr<TreeNode> node) {
    heap_.emplace_back(node);
    ++size_;
    maintain_heap(size_ - 1);
}

std::shared_ptr<TreeNode> MinHeap::pop() {
    auto res = heap_[0];
    heap_[0] = heap_[--size_];
    minimize_heap(0);
    return res;
}