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

const int MAX = 305;
int k, n, m;
int a[MAX], b[MAX];

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    cin >> k >> n >> m;

    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }

    for (int i = 1; i <= m; ++i) {
      cin >> b[i];
    }

    int up = 1, down = 1;
    bool flag = 1;
    vector<int> ans;
    while (up <= n || down <= m) {
//       debug(up);
      // debug(down);
      // debug(k);
      if (up <= n && !a[up]) {
        ans.push_back(a[up]);
        ++k;
        ++up;
      } else if (down <= m && !b[down]) {
        ans.push_back(b[down]);
        ++k;
        ++down;
      } else if (up <= n && down <= m && a[up] < b[down] && a[up] <= k) {
        ans.push_back(a[up]);
        ++up;
      } else if (down > m && a[up] <= k) {
        ans.push_back(a[up]);
        ++up;
      } else if (up <= n && down <= m && a[up] >= b[down] && b[down] <= k) {
        ans.push_back(b[down]);
        ++down;
      } else if (up > n && b[down] <= k) {
        ans.push_back(b[down]);
        ++down;
      } else {
        flag = 0;
        break;
      }
    }

    if (!flag)
      cout << -1;
    else
      for (auto x : ans)
        cout << x << " ";

    cout << endl;
  }
  return 0;
}
