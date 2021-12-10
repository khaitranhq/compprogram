#include <bits/stdc++.h>

#define debug(x) cerr << #x << " = " << x << endl;
#define debugarr(x, n)                                                         \
  {                                                                            \
    for (int _ = 0; _ < n; ++_)                                                \
      cerr << x[_] << " ";                                                     \
    cerr << endl;                                                              \
  }
#define debugarr2d(x, n, m)                                                    \
  {                                                                            \
    for (int __ = 0; __ < n; ++__)                                             \
      debugarr(x[__], m);                                                      \
    cerr << endl;                                                              \
  }
#define debugvi(x)                                                             \
  {                                                                            \
    for (int _ = 0; _ < x.size(); ++_)                                         \
      cerr << x[_] << " ";                                                     \
    cerr << endl;                                                              \
  }

using namespace std;

const int MAX = 5005;
int m, n;
bool a[MAX][MAX];
short int lr[MAX][MAX], rl[MAX][MAX], ud[MAX][MAX], du[MAX][MAX];

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
#endif

  cin >> m >> n;

  for (int i = 1; i <= m; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); ++j)
      a[i][j + 1] = s[j] - '0';
  }

  memset(lr, 0, sizeof(lr));
  memset(rl, 0, sizeof(rl));
  memset(ud, 0, sizeof(ud));
  memset(du, 0, sizeof(du));

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j)
      if (a[i][j])
        lr[i][j] = lr[i][j - 1] + 1;
      else
        lr[i][j] = 0;
    for (int j = n; j >= 1; --j)
      if (a[i][j])
        rl[i][j] = rl[i][j + 1] + 1;
      else
        rl[i][j] = 0;
  }

  for (int j = 1; j <= n; ++j) {
    for (int i = 1; i <= m; ++i)
      if (a[i][j])
        ud[i][j] = ud[i - 1][j] + 1;
      else
        ud[i][j] = 0;
    for (int i = m; i >= 1; --i)
      if (a[i][j])
        du[i][j] = du[i + 1][j] + 1;
      else
        du[i][j] = 0;
  }

  int maxSize = 0;
  int x, y;
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) {
      int size = min(lr[i][j], min(rl[i][j], min(ud[i][j], du[i][j])));
      if (maxSize < size) {
        maxSize = size;
        x = i; y = j;
      }
    }

  if (!maxSize) {
    cout << -1 ;
    return 0;
  }

  cout << 4 * maxSize - 3 << endl;
  cout << x << " " << y << endl;
  return 0;
}
