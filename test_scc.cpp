#include "kosaroju.h"
#include <fstream>
#include <iostream>
#include <sstream>

#define FILEPATH "graph.txt"

optional<vector<pair<int, int>>> io_read_edges(ifstream &file) {
  if (!file.is_open()) {
    return nullopt;
  }
  vector<pair<int, int>> graph;

  string line;
  while (getline(file, line)) {
    if (line.empty())
      continue;

    istringstream iss(line);
    int u, v;
    if (!(iss >> u >> v))
      continue;
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
  ifstream file(FILEPATH);
  auto graph = io_read_edges(file);
  file.close();
  if (!graph.has_value()) {
    cerr << "Error Parsing file" << endl;
    return 1;
  }
  auto scc = get_scc(graph.value());
  cout << "Connected Components are: " << endl;
  for (const auto &component : scc) {
    for (auto i : component) {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}
