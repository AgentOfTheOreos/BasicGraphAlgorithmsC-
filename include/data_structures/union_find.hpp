// alaasalah142@gmail.com

#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

#include <stdexcept>

namespace ds {

class UnionFind {
private:
    int* parent; 
    int* rank;
    int size;

public:
    // Constructor: Initialize n disjoint sets
    UnionFind(int n) : size(n) {
        if (n <= 0) {
            throw std::runtime_error("Size must be positive");
        }
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Copy constructor
    UnionFind(const UnionFind& other) : size(other.size) {
        parent = new int[size];
        rank = new int[size];

        for (int i = 0; i < size; ++i) {
            parent[i] = other.parent[i];
            rank[i] = other.rank[i];
        }
    }

    // Destructor
    ~UnionFind() {
        delete[] parent;
        delete[] rank;
    }

    // Assignment operator
    UnionFind& operator=(const UnionFind& other) {
        if (this == &other) {
            return *this;
        }

        delete[] parent;
        delete[] rank;

        size = other.size;
        parent = new int[size];
        rank = new int[size];

        for (int i = 0; i < size; ++i) {
            parent[i] = other.parent[i];
            rank[i] = other.rank[i];
        }

        return *this;
    }

    int find(int x) {
        if (x < 0 || x >= size) {
            throw std::runtime_error("Invalid element");
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

} // namespace ds

#endif // UNION_FIND_HPP