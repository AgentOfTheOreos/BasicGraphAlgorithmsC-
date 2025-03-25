// alaasalah142@gmail.com

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "graph.hpp"

namespace graph {

class Algorithms {
public:
    // Performs a Breadth-First Search starting at 'source' and returns a tree of the BFS sweep.
    static Graph bfs(const Graph& g, int source);

    // Performs a Depth-First Search starting at 'source' and returns a DFS tree/forest.
    static Graph dfs(const Graph& g, int source);

    // Dijkstra's algorithm to compute shortest paths from 'source'
    // returns a weighted tree representing the shortest paths.
    static Graph dijkstra(const Graph& g, int source);

    // Computes the Minimum Spanning Tree (MST) of the graph using Prim's algorithm.
    static Graph prim(const Graph& g);

    // Computes the MST using Kruskal's algorithm.
    static Graph kruskal(const Graph& g);
};

} // namespace graph

#endif // ALGORITHMS_HPP
