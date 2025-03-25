// alaasalah142@gmail.com

#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <stdexcept>

namespace ds {

template <typename T> // Generic
class DynamicArray {
private:
    T* data_;
    int size_;
    int capacity_;

    void resize(int new_capacity) {
        T* new_data = new T[new_capacity];
        for (int i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

public:
    // Default constructor with an initial capacity.
    DynamicArray() : data_(nullptr), size_(0), capacity_(4) {
        data_ = new T[capacity_];
    }

    // Constructor with a specified initial capacity.
    DynamicArray(int initial_capacity) : data_(nullptr), size_(0), capacity_(initial_capacity) {
        if (initial_capacity <= 0) {
            capacity_ = 4;
        }
        data_ = new T[capacity_];
    }

    // Copy constructor.
    DynamicArray(const DynamicArray& other)
        : data_(new T[other.capacity_]), size_(other.size_), capacity_(other.capacity_) {
        for (int i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    // Copy assignment operator.
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = new T[capacity_];
            for (int i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }

    ~DynamicArray() {
        delete[] data_;
    }

    int size() const {
        return size_;
    }

    int capacity() const {
        return capacity_;
    }

    void push_back(const T& value) {
        if (size_ >= capacity_) {
            resize(capacity_ * 2);
        }
        data_[size_] = value;
        ++size_;
    }

    void pop_back() {
        if (size_ == 0) {
            throw std::underflow_error("Cannot pop from an empty array");
        }
    
        --size_;
        
        if (size_ <= capacity_ / 4 && capacity_ > 4) {
            int new_capacity = capacity_ / 2;
            if (new_capacity < 4) new_capacity = 4;
            resize(new_capacity);
        }
    }
    

    // Unchecked access to elements
    T& operator[](int index) {
        return data_[index];
    }

    const T& operator[](int index) const {
        return data_[index];
    }

    // Bounds-checked access to elements
    T& at(int index) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of bounds");
        }
        return data_[index];
    }

    const T& at(int index) const {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of bounds");
        }
        return data_[index];
    }
};

} // namespace ds

#endif // DYNAMIC_ARRAY_HPP