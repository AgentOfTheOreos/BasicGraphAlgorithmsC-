// alaasalah142@gmail.com
// doctest_datastructures.cpp
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "../include/data_structures/dynamic_array.hpp"
#include "../include/data_structures/priority_queue.hpp"
#include "../include/data_structures/queue.hpp"
#include "../include/data_structures/union_find.hpp"
#include "../include/graph/graph.hpp"

TEST_CASE("=====Testing graph add and remove edges=====") {
    graph::Graph graph(5);

    graph.addEdge(0, 1, 1);
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 3, 3);
    graph.addEdge(3, 4, 4);
    graph.addEdge(4, 0, 5);

    graph.print_graph();

    std::cout << "=====Removing edges (0, 1) and (2, 3)...=====" << std::endl;

    graph.removeEdge(0, 1);
    graph.removeEdge(2, 3);

    std::cout << "=====Graph after edge removal:=====" << std::endl;

    graph.print_graph();

    std::cout << "=====Attempting to remove non-existant edge (3, 0) (Exception handling)...=====" << std::endl;

    CHECK_THROWS_AS(graph.removeEdge(3, 0), std::runtime_error);

    std::cout << "=====Exception caught and handled successfully.=====" << std::endl;
}

TEST_CASE("DynamicArray works correctly") {
    ds::DynamicArray<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    
    // Test push_back and element access
    CHECK(arr.size() == 3);
    CHECK(arr.at(0) == 10);
    CHECK(arr[2] == 30);
    
    // Test pop_back
    arr.pop_back();
    CHECK(arr.size() == 2);
}

TEST_CASE("Queue works correctly") {
    ds::Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    
    // Test front access
    CHECK(q.front() == 1);
    
    // Test dequeue
    q.dequeue();
    CHECK(q.front() == 2);
}

TEST_CASE("PriorityQueue works correctly") {
    ds::PriorityQueue pq;
    pq.insert(5, 100);
    pq.insert(2, 200);
    pq.insert(8, 300);
    
    // Check that the element with the smallest key is at the top.
    CHECK(pq.peek_min() == 200);
    
    int minVal = pq.extract_min();
    CHECK(minVal == 200);
    CHECK(pq.peek_min() == 100);
    
    // Test decrease_key: lowering the key for value 300 should make it new minimum.
    pq.decrease_key(300, 1);
    CHECK(pq.peek_min() == 300);
}

TEST_CASE("UnionFind works correctly") {
    ds::UnionFind uf(5);
    uf.unionSets(0, 1);
    uf.unionSets(3, 4);
    uf.unionSets(1, 3);  // Now vertices 0,1,3,4 should be connected.
    
    CHECK(uf.find(0) == uf.find(4));  // They belong to the same set.
    CHECK(uf.find(2) != uf.find(0));  // Vertex 2 still separate.
}