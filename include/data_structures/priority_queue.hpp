// alaasalah142@gmail.com

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "dynamic_array.hpp"

namespace ds {

struct PQNode {
    int key;    // Priority (distance in Dijkstra)
    int value;  // Associated vertex (or data)

    PQNode(int k = 0, int v = 0) : key(k), value(v) {
        
    }
};

// Min-Heap based
class PriorityQueue {
private:
    ds::DynamicArray<PQNode> heap;

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapify_up(int index) {
        while (index > 0 && heap[parent(index)].key > heap[index].key) {
            PQNode temp = heap[index];
            heap[index] = heap[parent(index)];
            heap[parent(index)] = temp;
            index = parent(index);
        }
    }
    void heapify_down(int index) {
        int smallest = index;
        int l = left(index);
        int r = right(index);

        if (l < heap.size() && heap[l].key < heap[smallest].key) {
            smallest = l;
        }
        if (r < heap.size() && heap[r].key < heap[smallest].key) {
            smallest = r;
        }

        if (smallest != index) {
            PQNode temp = heap[index];
            heap[index] = heap[smallest];
            heap[smallest] = temp;
            heapify_down(smallest);
        }
    }

public:
    void insert(int key, int value) {
        PQNode node(key, value);
        heap.push_back(node);
        heapify_up(heap.size() - 1);
    }

    int peek_min() const {
        if (is_empty()) {
            throw std::underflow_error("Queue is empty");
        }
        return heap[0].value;
    }

    int extract_min() {
        if (is_empty()) {
            throw std::underflow_error("Queue is empty");
        }
        int minValue = heap[0].value;
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify_down(0);
        return minValue;
    }

    bool is_empty() const {
        return heap.size() == 0;
    }

    void decrease_key(int value, int new_key) {
        for (int i = 0; i < heap.size(); ++i) {
            if (heap[i].value == value) {
                if (new_key > heap[i].key) {
                    throw std::runtime_error("New key is greater than current key");
                }
                heap[i].key = new_key;
                heapify_up(i);
                return;
            }
        }
        throw std::runtime_error("Value not found in priority queue");
    }
};

} // namespace ds

#endif // PRIORITY_QUEUE_HPP