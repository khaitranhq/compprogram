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
using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAX = 1e3 + 5;
const char typeArrow[4] = {'<', '>', '^', 'v'};
int n, m;
int a[MAX][MAX];
bool isVisited[MAX][MAX];
int ans;

void enter() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (size_t j = 0; j < s.size(); ++j)
      for (int k = 0; k < 4; ++k)
        if (typeArrow[k] == s[j]) {
          a[i][j] = k;
          break;
        }
  }
}

/**
 * Spread and process with same type arrow
 *
 * @param i: x-index
 * @param j: y-index
 * @param direction: direction will be iterated. 0 for horizontal, 1 for
 * vertical
 */
void calc(int i, int j, bool direction) {
  // cout << "Start a components..." << endl;
  // debug(i);
  // debug(j);
  // debug(direction);

  int rt = 0;
  if (!direction)
    for (int k = i; k <= n; ++k) {
      if (a[k][j] < 2)
        break;

      // debug(k);
      isVisited[k][j] = 1;
      rt += (a[k][j] == 3);
      if (a[k][j] == 2)
        ans += rt;
    }
  else
    for (int k = j; k <= m; ++k) {
      if (a[i][k] > 1)
        break;

      // debug(k);
      isVisited[i][k] = 1;
      rt += (a[i][k] == 0);
      if (a[i][k] == 1)
        ans += rt;
    }
  // debug(ans);
  // cout << endl;
}

void solve() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (!isVisited[i][j])
        calc(i, j, a[i][j] < 2);

  cout << ans;
}

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  enter();
  solve();
  return 0;
}
