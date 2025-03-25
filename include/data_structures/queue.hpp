// alaasalah142@gmail.com

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "dynamic_array.hpp"

namespace ds {

template <typename T>
class Queue {
private:
    ds::DynamicArray<T> data;

public:
    void enqueue(const T& item) {
        data.push_back(item);
    }

    // This shifts all elements to the left.
    void dequeue() {
        if (empty()) {
            throw std::underflow_error("Cannot dequeue an empty queue");
        }
        int n = data.size();
        for (int i = 0; i < n - 1; ++i) {
            data[i] = data[i + 1];
        }
        data.pop_back();
    }

    T& front() {
        if (empty()) {
            throw std::underflow_error("Cannot dequeue an empty queue");
        }
        return data[0];
    }

    const T& front() const {
        if (empty()) {
            throw std::underflow_error("Cannot dequeue an empty queue");
        }
        return data[0];
    }

    bool empty() const {
        return data.size() == 0;
    }

    int size() const {
        return data.size();
    }
};

} // namespace ds

#endif // QUEUE_HPP