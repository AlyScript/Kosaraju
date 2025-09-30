/*
 * Implementation of Kosaroju's algorithm to find SCC.
 *
 */

#include "kosaroju.h"
#include <unordered_set>

using namespace std;

void dfs(const int &node, const unordered_map<int, vector<int>> &adjacency_list, vector<int> &ordered_nodes,
         unordered_set<int> &visited) {
  if (visited.count(node))
    return;
  visited.insert(node);
  for (const auto &neighbor : adjacency_list.at(node)) {
    if (visited.count(neighbor)) {
      continue;
    }
    dfs(neighbor, adjacency_list, ordered_nodes, visited);
  }
  ordered_nodes.push_back(node);
}

void get_components(const int node, const unordered_map<int, vector<int>> &adjacency_list, vector<int> &ordered_nodes,
                    unordered_set<int> &visited, vector<int> &component) {
  if (visited.count(node))
    return;
  visited.insert(node);
  component.push_back(node);
  for (auto neighbor : adjacency_list.at(node)) {
    if (visited.count(neighbor))
      continue;
    get_components(neighbor, adjacency_list, ordered_nodes, visited, component);
  }
}

/*
 * Reverse adjacency list
 */
unordered_map<int, vector<int>> reverse_graph(const unordered_map<int, vector<int>> &adj) {
  unordered_map<int, vector<int>> reversed;
  for (auto [node, neighbors] : adj) {
    for (auto neighbor : neighbors) {
      if (reversed.count(neighbor))
        reversed[neighbor].push_back(node);
      else
        reversed[neighbor] = {node};
    }
  }
  return reversed;
}

/*
 * Paramaters: List of edges in a graph
 * Returns: Vector of SCC
 */
vector<vector<int>> get_scc(const vector<pair<int, int>> &graph) {
  unordered_map<int, vector<int>> adj;
  for (const auto [u, v] : graph) {
    if (adj.count(u))
      adj[u].push_back(v);
    else
      adj[u] = {v};
    if (!adj.count(v))
      adj[v] = {};
  }

  vector<int> ordered_nodes;
  unordered_set<int> visited;
  for (auto [u, v] : graph) {
    dfs(u, adj, ordered_nodes, visited);
  }

  adj = reverse_graph(adj);

  visited.clear();
  vector<vector<int>> components;
  for (int i = ssize(ordered_nodes) - 1; i >= 0; i--) {
    int node = ordered_nodes[i];
    if (visited.count(node))
      continue;
    vector<int> component;
    get_components(node, adj, ordered_nodes, visited, component);
    components.push_back(component);
  }

  return components;
}
