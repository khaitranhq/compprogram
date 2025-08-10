#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(int startBoxIndex, int targetBoxIndex,
                vector<vector<int>> &openableBoxes) {
  queue<int> q;
  vector<int> beforeBox(openableBoxes.size(), -1);
  q.push(startBoxIndex);
  beforeBox[startBoxIndex] = startBoxIndex;

  while (!q.empty()) {
    int currentBox = q.front();
    q.pop();

    if (currentBox == targetBoxIndex) {
      // Reconstruct path
      vector<int> path;
      int current = targetBoxIndex;
      while (current != startBoxIndex) {
        path.push_back(current);
        current = beforeBox[current];
      }
      path.push_back(startBoxIndex);
      reverse(path.begin(), path.end());
      return path;
    }

    for (int box : openableBoxes[currentBox]) {
      if (beforeBox[box] == -1) {
        beforeBox[box] = currentBox;
        q.push(box);
      }
    }
  }

  // No path found
  return vector<int>();
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;

    // Initialize openableBoxes with n+1 elements for 1-based indexing
    vector<vector<int>> openableBoxes(n + 1);

    // Read keys for boxes 1 to n-1 (box n doesn't have a key since it's the
    // target)
    for (int i = 1; i < n; ++i) {
      int m;
      cin >> m;
      for (int j = 0; j < m; ++j) {
        int box;
        cin >> box;
        openableBoxes[i].push_back(box);
      }
      // Sort adjacency list for lexicographic ordering
      sort(openableBoxes[i].begin(), openableBoxes[i].end());
    }

    // Find path from box 1 to box n
    vector<int> pathToBox = bfs(1, n, openableBoxes);
    if (pathToBox.empty()) {
      cout << "-1" << endl;
    } else {
      cout << pathToBox.size() - 1 << endl; // Number of steps (edges)
      for (size_t i = 0; i < pathToBox.size() - 1; ++i) {
        cout << pathToBox[i] << " ";
      }
      cout << endl;
    }
    cout << endl; // Blank line after each test case as required by SPOJ
  }
  return 0;
}
