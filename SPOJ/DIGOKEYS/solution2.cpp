#include "algorithm"
#include "iostream"
#include "queue"
#include "vector"

#define pb push_back

using namespace std;

const int MAX_NODES = 1e5 + 1;

vector<int> adjacency_list[MAX_NODES];

int num_test_cases;

void bfs(int start_node, int end_node) {
  vector<bool> is_visited(end_node + 1, 0);
  vector<int> parent(end_node + 1, -1);
  queue<int> node_queue;
  node_queue.push(start_node);
  is_visited[start_node] = 1;
  while (!node_queue.empty()) {
    int current_node = node_queue.front();
    node_queue.pop();
    if (current_node == end_node)
      break;
    for (auto neighbor : adjacency_list[current_node])
      if (!is_visited[neighbor]) {
        is_visited[neighbor] = 1;
        node_queue.push(neighbor);
        parent[neighbor] = current_node;
      }
  }
  if (!is_visited[end_node]) {
    cout << -1;
    return;
  }
  vector<int> path;
  for (int current_vertex = end_node; current_vertex != -1;
       current_vertex = parent[current_vertex])
    path.pb(current_vertex);
  reverse(path.begin(), path.end());
  if (path.empty())
    cout << -1 << "\n\n";
  else {
    cout << path.size() - 1 << "\n";
    for (int path_index = 0; path_index <= (int)path.size() - 2; path_index++)
      cout << path[path_index] << " ";
    cout << "\n\n";
  }
}

int main() {
  cin >> num_test_cases;
  while (num_test_cases--) {
    int num_nodes;
    cin >> num_nodes;
    for (int node_index = 1; node_index <= num_nodes; node_index++)
      adjacency_list[node_index].clear();
    for (int node_index = 1; node_index <= num_nodes - 1; node_index++) {
      int num_connections;
      cin >> num_connections;
      for (int connection_index = 1; connection_index <= num_connections;
           connection_index++) {
        int connected_node;
        cin >> connected_node;
        adjacency_list[node_index].pb(connected_node);
      }
      sort(adjacency_list[node_index].begin(),
           adjacency_list[node_index].end());
    }
    bfs(1, num_nodes);
  }
  return 0;
}
