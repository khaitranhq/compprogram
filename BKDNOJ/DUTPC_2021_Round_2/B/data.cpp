#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)                                                    \
  {                                                                            \
    for (int _ = 0; _ < n; ++_) {                                              \
      for (int __ = 0; __ < m; ++__)                                           \
        cout << x[_][__] << " ";                                               \
      cout << endl;                                                            \
    }                                                                          \
    cout << endl;                                                              \
  }
#define debugarr(x, n)                                                         \
  {                                                                            \
    for (int _ = 0; _ < n; ++_)                                                \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }
#define debugvi(x)                                                             \
  {                                                                            \
    for (int _ = 0; _ < x.size(); ++_)                                         \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }

#define fi first
#define se second
#define pb push_back

#define before adsfasdfa
using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAX = 1e3 + 5;
int n, m;
int a[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
queue<ii> before, after;

int main() {
#ifndef ONLINE_JUDGE
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (a[i][j] == 2)
        before.push(ii(i, j));
    }

  int ans = 0;
  while (1) {
    while (before.size()) {
      ii u = before.front();
      before.pop();

      for (int i = 0; i < 4; ++i) {
        ii v = ii(u.fi + dx[i], u.se + dy[i]);

        if (v.fi < 0 || v.fi >= n)
          continue;
        if (v.se < 0 || v.se >= m)
          continue;

        if (a[v.fi][v.se] == 1) {
          a[v.fi][v.se] = 2;
          after.push(v);
        }
      }
    }

    if (!after.size())
      break;

    while (after.size()) {
      before.push(after.front());
      after.pop();
    }

    ++ans;
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (a[i][j] == 1) {
        cout << -1;
        return 0;
      }

  cout << ans;
  return 0;
}
