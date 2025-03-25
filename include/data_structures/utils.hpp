// alaasalah142@gmail.com

#ifndef UTILS_HPP
#define UTILS_HPP

#include "../graph/graph.hpp"

namespace ds {

class Utils {
public:
    static void dfsUtil(const graph::Graph& g, graph::Graph& tree, int u, bool* visited);
};

} // namespace ds

#endif // UTILS_HPP