#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr(x, n)                                                         \
  {                                                                            \
    for (int _ = 0; _ < n; ++_)                                                \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }
#define debugarr2d(x, n, m)                                                    \
  {                                                                            \
    for (int __ = 0; __ < n; ++__)                                             \
      debugarr(x[__], m);                                                      \
    cout << endl;                                                              \
  }
#define debugvi(x)                                                             \
  {                                                                            \
    for (int _ = 0; _ < x.size(); ++_)                                         \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }

using namespace std;

typedef pair<int, int> ii;
const int MAX = 1e5 + 5;
int n, m;
int a[MAX], s[MAX];

void solve() {
  s[0] = 0;
  for (int i = 1; i <= n; ++i)
    s[i] = s[i - 1] + a[i];

  int l = -1, lastMIndex = -1;
  vector<ii> ans;
  for (int i = 1; i <= n + 1; ++i) {
    if ((i == n + 1 || a[i] < m) && lastMIndex != -1) {
      // debug(i)
      ans.push_back({l, i - 1});
      l = -1; lastMIndex = -1;
      continue;
    }

    if (a[i] < m) {
      lastMIndex = -1;
      l = -1;
    }

    if (a[i] >= m) {
      if (l == -1)
        l = i;

      if (a[i] == m) {
        if (lastMIndex != -1) {
          // debug(i)
          ans.push_back({l, i - 1});
          l = lastMIndex + 1;
        }
        lastMIndex = i;
      }
    }
  }

  int res = 0;
  for (int i = 0; i < ans.size(); ++i) {
/*     debug(ans[i].first); */
    /* debug(ans[i].second); */
    /* cout << endl; */
    res = max(res, s[ans[i].second] - s[ans[i].first - 1]);
  }

  cout << res << endl;
}

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
      cin >> a[i];

    solve();
  }

  return 0;
}
