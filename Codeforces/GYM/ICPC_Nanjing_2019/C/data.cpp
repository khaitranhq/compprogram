#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const long long MOD = 1e9 + 7;
int n, m, a[N][N];
long long dp[N][N][5];
bool vis[N][N];
int in[N][N], out[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool check(int u, int v) {
  if (u >= 1 && u <= n && v >= 1 && v <= m)
    return true;
  else
    return false;
}
void dfs(int u, int v) {
  if (vis[u][v])
    return;
  vis[u][v] = 1;
  if (out[u][v] == 0)
    dp[u][v][1] = 1;
  for (int i = 0; i < 4; i++) {
    int x = u + dx[i];
    int y = v + dy[i];
    if (check(x, y) && a[u][v] + 1 == a[x][y]) {
      dfs(x, y);
      dp[u][v][2] = (dp[u][v][2] + dp[x][y][1]) % MOD;
      dp[u][v][3] = (dp[u][v][3] + dp[x][y][2]) % MOD;
      dp[u][v][4] = (dp[u][v][4] + dp[x][y][3] + dp[x][y][4]) % MOD;
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> a[i][j];
  memset(vis, 0, sizeof(vis));
  memset(dp, 0, sizeof(dp));
  memset(out, 0, sizeof(out));
  memset(in, 0, sizeof(in));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (check(x, y) && a[i][j] + 1 == a[x][y]) {
          in[x][y]++;
          out[i][j]++;
        }
      }
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      dfs(i, j);
    }
  long long res = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (in[i][j] == 0) {
        res = (res + dp[i][j][4]) % MOD;
      }
  cout << res;
}
