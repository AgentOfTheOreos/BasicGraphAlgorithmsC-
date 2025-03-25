// alaasalah142@gmail.com

#include "../../include/data_structures/utils.hpp"
#include "../../include/graph/graph.hpp"

namespace ds {

void Utils::dfsUtil(const graph::Graph& g, graph::Graph& tree, int u, bool* visited) {
    visited[u] = true;
    const ds::DynamicArray<graph::Edge>& neighbors = g.getNeighbors(u);
    for (int i = 0; i < neighbors.size(); ++i) {
        int v = neighbors.at(i).destination;
        if (!visited[v]) {
            tree.addEdge(u, v, neighbors.at(i).weight);
            Utils::dfsUtil(g, tree, v, visited);
        }
    }
}

} // namespace ds
