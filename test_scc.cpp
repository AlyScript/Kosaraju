#pragma once

#include "kosaroju.h"
#include <iostream>
#include <sstream>

vector<pair<int, int>> io_read_edge() {
  vector<pair<int, int>> graph;

  string line;
  while (getline(cin, line)) {
    if (line.empty())
      break;

    istringstream iss(line);
    int u, v;
    iss >> u >> v;
    graph.emplace_back(u, v);
  }
  return graph;
}

/* Input the graph as lines of two integers that are space separates representing an edge from x --> y
 *  For example:
 *  2 1
 *  3 1
 *  1 2
 *
 *  Is the graph
 *  2 <--> 1 <-- 3
 *
 */
int main() {
  auto graph = io_read_edge();
  auto scc = get_scc(graph);
  cout << "Connected Components are: " << endl;
  for (const auto &component : scc) {
    for (auto i : component) {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}
