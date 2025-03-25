// alaasalah142@gmail.com
// doctest_algorithms.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "../include/graph/graph.hpp"
#include "../include/graph/algorithms.hpp"

int countUniqueEdges(const graph::Graph& g) {
    int n = g.getNumVertices();
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += g.getNeighbors(i).size();
    }
    // Each undirected edge is stored twice.
    return total / 2;
}

TEST_CASE("BFS returns a valid spanning tree for a connected graph") {
    int n = 6;
    graph::Graph g(n);
    // Create a connected graph.
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    // Add extra edges.
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    auto bfsTree = graph::Algorithms::bfs(g, 0);
    // A spanning tree on a connected graph with 6 vertices has 5 unique edges.
    CHECK(countUniqueEdges(bfsTree) == 5);
}

TEST_CASE("DFS returns a valid spanning tree for a connected graph") {
    int n = 6;
    graph::Graph g(n);
    // Same graph structure as BFS test.
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    auto dfsTree = graph::Algorithms::dfs(g, 0);
    // A spanning tree should have 5 unique edges.
    CHECK(countUniqueEdges(dfsTree) == 5);
}

TEST_CASE("Dijkstra returns a valid shortest path tree for a weighted graph") {
    int n = 5;
    graph::Graph g(n);
    // Construct a weighted graph.
    // Graph diagram:
    // 0--(10)--1
    //  \       /
    //   (3)  (1)
    //     \  /
    //      2 --(8)-- 3
    //       \         /
    //       (2)    (7)
    //         \   /
    //           4
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 7);

    auto dijkstraTree = graph::Algorithms::dijkstra(g, 0);
    // For a connected graph with 5 vertices, a spanning tree has 4 unique edges.
    CHECK(countUniqueEdges(dijkstraTree) == 4);
}

TEST_CASE("Prim returns a valid MST for a weighted graph") {
    int n = 5;
    graph::Graph g(n);
    // Using the same weighted graph as the Dijkstra test.
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 7);

    auto mst = graph::Algorithms::prim(g);
    // MST for a graph with 5 vertices must have 4 unique edges.
    CHECK(countUniqueEdges(mst) == 4);
}

TEST_CASE("Kruskal returns a valid MST for a weighted graph") {
    int n = 5;
    graph::Graph g(n);
    // Again, using the same weighted graph.
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 7);

    auto mst = graph::Algorithms::kruskal(g);
    CHECK(countUniqueEdges(mst) == 4);
}