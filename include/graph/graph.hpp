// alaasalah142@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "../data_structures/dynamic_array.hpp"

namespace graph {

struct Edge {
    int destination;
    int weight;
    // Default constructor for compatibility with dynamic array.
    Edge() : destination(-1), weight(1) {}
    // Constructor with default weight of 1.
    Edge(int dest, int w = -1) : destination(dest), weight(w) {}
};

class Graph {
private:
    int numVertices;
    // Adjacency list: each vertex has a dynamic array of its edges.
    ds::DynamicArray< ds::DynamicArray<Edge> > adjList;

public:
    // Constructor: initializes the graph with a fixed number of vertices.
    // The adjacency list is initialized with one dynamic array per vertex.
    Graph(int numVertices);

    // Destructor.
    ~Graph();

    void addEdge(int source, int destination, int weight = 1);

    void removeEdge(int source, int destination);

    void print_graph() const;

    const ds::DynamicArray<Edge>& getNeighbors(int vertex) const;

    int getNumVertices() const { return numVertices; }
};

} // namespace graph

#endif // GRAPH_HPP
