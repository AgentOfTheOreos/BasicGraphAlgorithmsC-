#include <iostream>
#include "include/graph/graph.hpp"
#include "include/graph/algorithms.hpp"

using namespace graph;

int main() {
    Graph g(6);
    
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 5);
    g.addEdge(4, 5, 6);
    g.addEdge(1, 2, 1); // extra edge to demonstrate multiple paths

    std::cout << "Original Graph:" << std::endl;
    g.print_graph();
    
    std::cout << "\nBFS Spanning Tree (starting at vertex 0):" << std::endl;
    Graph bfsTree = Algorithms::bfs(g, 0);
    bfsTree.print_graph();

    std::cout << "\nDFS Spanning Tree/Forest (starting at vertex 0):" << std::endl;
    Graph dfsTree = Algorithms::dfs(g, 0);
    dfsTree.print_graph();

    std::cout << "\nDijkstra's Shortest Path Tree (starting at vertex 0):" << std::endl;
    Graph dijkstraTree = Algorithms::dijkstra(g, 0);
    dijkstraTree.print_graph();

    std::cout << "\nPrim's Minimum Spanning Tree:" << std::endl;
    Graph primTree = Algorithms::prim(g);
    primTree.print_graph();

    std::cout << "\nKruskal's Minimum Spanning Tree:" << std::endl;
    Graph kruskalTree = Algorithms::kruskal(g);
    kruskalTree.print_graph();

    return 0;
}
