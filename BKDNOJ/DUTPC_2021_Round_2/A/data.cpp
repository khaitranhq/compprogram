#include <bits/stdc++.h>
using namespace std;

int n, m;
char g[2005][2005];
int c[2005][2005];

int main() {
#ifndef ONLINE_JUDGE
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      g[i][j] = c;
    }

  queue<tuple<int, int, int>> Q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (g[i][j] == '.') {
        Q.push(make_tuple(i, j, -1));
      }
    }

  for (int i = 0; i <= m + 1; i++) {
    c[0][i] = 1;
    c[n + 1][i] = 1;
  }
  for (int i = 0; i <= n + 1; i++) {
    c[i][0] = 1;
    c[i][m + 1] = 1;
  }
  // for (int i=0; i<=n+1; i++){
  //    for (int j=0; j<=m+1; j++) {
  //        cout << c[i][j];
  //    }
  //    cout << endl;
  //}

  unordered_map<char, int> dangerLevel;
  while (!Q.empty()) {
    int x, y, d;
    tie(x, y, d) = Q.front();
    Q.pop();

    if (c[x][y])
      continue;
    c[x][y] = 1;

    // fprintf(stderr, "x=%d y=%d d=%d\n", x, y, d);

    if (dangerLevel.find(g[x][y]) == dangerLevel.end()) {
      dangerLevel[g[x][y]] = d;
    }

    for (int dx : {-1, 0, 1}) {
      for (int dy : {-1, 0, 1}) {
        if (c[x + dx][y + dy])
          continue;
        if (g[x + dx][y + dy] != g[x][y]) {
          Q.push(make_tuple(x + dx, y + dy, d + 1));
        } else {
          Q.push(make_tuple(x + dx, y + dy, d));
        }
      }
    }
  }

  vector<pair<char, int>> result;
  for (auto &p : dangerLevel) {
    if (p.first == '.')
      continue;
    result.push_back({p.first, p.second});
  }
  sort(result.begin(), result.end());
  for (auto &p : result) {
    printf("%c %d\n", p.first, p.second);
  }
}
