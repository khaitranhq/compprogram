#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<vector<int>> ans(n - 2, vector<int>(n - 2, 0));
    for (int i = 0; i < n - 2; ++i) {
      for (int j = 0; j < n - 2; ++j) {
        int maxValue = 0;

        for (int incI = 0; incI < 3; ++incI)
          for (int incJ = 0; incJ < 3; ++incJ)
            maxValue = max(maxValue, grid[i + incI][j + incJ]);

        ans[i][j] = maxValue;
      }
    }
    return ans;
  }
};

int main() {
  // freopen("test/0.inp", "r", stdin);
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
    }

  Solution solution;
  vector<vector<int>> ans = solution.largestLocal(grid);
  for (vector<int> row : ans) {
    for (int cell : row)
      cout << cell << " ";
    cout << endl;
  }
  return 0;
}
