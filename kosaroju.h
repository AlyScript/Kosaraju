#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void dfs(const int &node, const unordered_map<int, vector<int>> &adjacency_list, vector<int> &ordered_nodes,
         unordered_set<int> &visited);
void get_components(const int node, const unordered_map<int, vector<int>> &adjacency_list, vector<int> &ordered_nodes,
                    unordered_set<int> &visited, vector<int> &component);
unordered_map<int, vector<int>> reverse_graph(const unordered_map<int, vector<int>> &adj);
vector<vector<int>> get_scc(const vector<pair<int, int>> &graph);
