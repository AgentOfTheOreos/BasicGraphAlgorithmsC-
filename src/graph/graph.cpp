// alaasalah142@gmail.com

#include "../../include/graph/graph.hpp"

#include <iostream>
#include <stdexcept>

namespace graph {

Graph::Graph(int numVertices) : numVertices(numVertices), adjList() {
    if (numVertices <= 0) {
        throw std::runtime_error("Number of vertices must be positive");
    }

    for (int i = 0; i < numVertices; ++i) {
        ds::DynamicArray<Edge> edges;
        adjList.push_back(edges);
    }
}

Graph::~Graph() {
    // Destructor: The dynamic arrays clean up their own allocated memory.
}

void Graph::addEdge(int source, int destination, int weight) {
    if (source < 0 || source >= numVertices || destination < 0 || destination >= numVertices) {
        throw std::runtime_error("Invalid vertex index");
    } 

    if (source == destination) {
        throw std::runtime_error("Edge cannot exist between a vertex and itself");
    }

    // Undirected
    Edge edgeToDestination(destination, weight);
    Edge edgeToSource(source, weight);
    adjList[source].push_back(edgeToDestination);
    adjList[destination].push_back(edgeToSource);
}

void Graph::removeEdge(int source, int destination) {
    if (source < 0 || source >= numVertices || destination < 0 || destination >= numVertices) {
        throw std::runtime_error("Invalid vertex index");
    } 
    
    if (source == destination) {
        throw std::runtime_error("Edge cannot exist between a vertex and itself");
    }
    
    bool removedFromSource = false;
    bool removedFromDestination = false;

    // Remove edge from source's list.
    {
        int n = adjList[source].size();
        for (int i = 0; i < n; ++i) {
            if (adjList[source].at(i).destination == destination) {
                // Shift subsequent edges left.
                for (int j = i; j < n - 1; ++j) {
                    adjList[source][j] = adjList[source][j + 1];
                }
                // Remove the last (now duplicate) element.
                adjList[source].pop_back();
                removedFromSource = true;
                break;
            }
        }
    }

    // Remove the edge from the destination's list.
    {
        int n = adjList[destination].size();
        for (int i = 0; i < n; ++i) {
            if (adjList[destination].at(i).destination == source) {
                for (int j = i; j < n - 1; ++j) {
                    adjList[destination][j] = adjList[destination][j + 1];
                }
                adjList[destination].pop_back();
                removedFromDestination = true;
                break;
            }
        }
    }
    
    if (!removedFromSource || !removedFromDestination) {
        throw std::runtime_error("Edge does not exist");
    }
}

const ds::DynamicArray<graph::Edge>& Graph::getNeighbors(int vertex) const {
    if (vertex < 0 || vertex >= numVertices) {
        throw std::runtime_error("Invalid vertex index");
    }
    return adjList.at(vertex);
}

void Graph::print_graph() const {
    std::cout << "Graph adjacency list:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vertex " << i << ":";
        int numEdges = adjList[i].size();
        for (int j = 0; j < numEdges; ++j) {
            // Each edge is printed as (destination, weight)
            std::cout << " (v: " << adjList[i].at(j).destination 
                      << ", w: " << adjList[i].at(j).weight << ")";
        }
        std::cout << std::endl;
    }
}

} // namespace graph