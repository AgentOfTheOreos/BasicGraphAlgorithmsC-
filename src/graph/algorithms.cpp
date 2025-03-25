// alaasalah142@gmail.com

#include "../../include/graph/algorithms.hpp"
#include "../../include/graph/graph.hpp"
#include "../../include/data_structures/queue.hpp"
#include "../../include/data_structures/priority_queue.hpp"
#include "../../include/data_structures/union_find.hpp"
#include "../../include/data_structures/utils.hpp"

namespace graph {

Graph Algorithms::bfs(const Graph& g, int source) {
    int n = g.getNumVertices();
    Graph tree(n);
    bool* visited = new bool[n];
    for (int i = 0; i < n; ++i)
        visited[i] = false;

    ds::Queue<int> q;
    visited[source] = true;
    q.enqueue(source);

    while (!q.empty()) {
        int u = q.front();
        q.dequeue();
        const ds::DynamicArray<Edge>& neighbors = g.getNeighbors(u);
        for (int i = 0; i < neighbors.size(); ++i) {
            int v = neighbors.at(i).destination;
            if (!visited[v]) {
                visited[v] = true;
                // Record the tree edge for BFS.
                tree.addEdge(u, v, neighbors.at(i).weight);
                q.enqueue(v);
            }
        }
    }
    delete[] visited;
    return tree;
}

Graph Algorithms::dfs(const Graph& g, int source) {
    int n = g.getNumVertices();
    Graph tree(n);
    bool* visited = new bool[n];
    for (int i = 0; i < n; ++i)
        visited[i] = false;

    ds::Utils::dfsUtil(g, tree, source, visited);
    delete[] visited;
    return tree;
}

Graph Algorithms::dijkstra(const Graph& g, int source) {
    int n = g.getNumVertices();
    Graph tree(n);
    const int INF = 1000000000;

    // Arrays to hold the shortest distances and the parent of each vertex.
    int* dist = new int[n];
    int* parent = new int[n];
    bool* processed = new bool[n];

    for (int i = 0; i < n; ++i) {
        dist[i] = INF;
        parent[i] = -1;
        processed[i] = false;
    }
    dist[source] = 0;

    ds::PriorityQueue pq;
    pq.insert(0, source);

    while (!pq.is_empty()) {
        int u = pq.extract_min();
        if (processed[u])
            continue;
        processed[u] = true;

        const ds::DynamicArray<Edge>& neighbors = g.getNeighbors(u);
        for (int i = 0; i < neighbors.size(); ++i) {
            int v = neighbors.at(i).destination;
            int weight = neighbors.at(i).weight;
            if (!processed[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.insert(dist[v], v);
            }
        }
    }

    // Construct the shortest path tree using the parent array.
    for (int v = 0; v < n; ++v) {
        if (v != source && parent[v] != -1) {
            // Find the edge weight from parent[v] to v.
            const ds::DynamicArray<Edge>& nbrs = g.getNeighbors(parent[v]);
            int w = 0;
            for (int j = 0; j < nbrs.size(); ++j) {
                if (nbrs.at(j).destination == v) {
                    w = nbrs.at(j).weight;
                    break;
                }
            }
            tree.addEdge(parent[v], v, w);
        }
    }

    delete[] dist;
    delete[] parent;
    delete[] processed;
    return tree;
}

Graph Algorithms::prim(const Graph& g) {
    int n = g.getNumVertices();
    Graph tree(n);
    const int INF = 1000000000;
    int* key = new int[n];
    int* parent = new int[n];
    bool* inMST = new bool[n];

    for (int i = 0; i < n; ++i) {
        key[i] = INF;
        parent[i] = -1;
        inMST[i] = false;
    }
    key[0] = 0;

    ds::PriorityQueue pq;
    pq.insert(0, 0);

    while (!pq.is_empty()) {
        int u = pq.extract_min();
        inMST[u] = true;
        const ds::DynamicArray<Edge>& neighbors = g.getNeighbors(u);
        for (int i = 0; i < neighbors.size(); ++i) {
            int v = neighbors.at(i).destination;
            int weight = neighbors.at(i).weight;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.insert(key[v], v);
            }
        }
    }

    // Build the MST from the parent array.
    for (int v = 1; v < n; ++v) {
        if (parent[v] != -1) {
            tree.addEdge(parent[v], v, key[v]);
        }
    }

    delete[] key;
    delete[] parent;
    delete[] inMST;
    return tree;
}

Graph Algorithms::kruskal(const Graph& g) {
    int n = g.getNumVertices();
    Graph tree(n);

    // Local structure to hold a full edge (source, destination, weight).
    struct FullEdge {
        int u, v, weight;
    };

    ds::DynamicArray<FullEdge> allEdges;
    // Collect each edge only once (for undirected graphs, use u < v).
    for (int u = 0; u < n; ++u) {
        const ds::DynamicArray<Edge>& nbrs = g.getNeighbors(u);
        for (int i = 0; i < nbrs.size(); ++i) {
            int v = nbrs.at(i).destination;
            int weight = nbrs.at(i).weight;
            if (u < v) {
                FullEdge fe;
                fe.u = u;
                fe.v = v;
                fe.weight = weight;
                allEdges.push_back(fe);
            }
        }
    }

    // A simple bubble sort on the collected edges by weight.
    for (int i = 0; i < allEdges.size(); ++i) {
        for (int j = i + 1; j < allEdges.size(); ++j) {
            if (allEdges.at(j).weight < allEdges.at(i).weight) {
                FullEdge temp = allEdges.at(i);
                allEdges[i] = allEdges.at(j);
                allEdges[j] = temp;
            }
        }
    }

    ds::UnionFind uf(n);
    // Process edges in sorted order.
    for (int i = 0; i < allEdges.size(); ++i) {
        FullEdge fe = allEdges.at(i);
        if (uf.find(fe.u) != uf.find(fe.v)) {
            uf.unionSets(fe.u, fe.v);
            tree.addEdge(fe.u, fe.v, fe.weight);
        }
    }
    return tree;
}

} // namespace graph
