#include <bits/stdc++.h>

#define debug(x) cerr << #x << " = " << x << endl;
#define debugarr(x, n)                                                         \
  {                                                                            \
    for (int _ = 1; _ <= n; ++_)                                               \
      cerr << x[_] << " ";                                                     \
    cerr << endl;                                                              \
  }
#define debugarr2d(x, n, m)                                                    \
  {                                                                            \
    for (int __ = 1; __ <= n; ++__)                                            \
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

typedef long long ll;
const int MAX = 1e3 + 5;
const ll BASE = 1e9 + 7;
int n;
int a[MAX];

int main() {
  freopen("data.inp", "r", stdin);
  freopen("data.ans", "w", stdout);
  cin >> n;

  ll ans = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ans = 1LL * ans * a[i];
  }

  for (int i = 1; i <= n; ++i) {
    ll mul = 1;
    for (int j = 1; j <= n; ++j)
      if (i != j)
        mul = 1ll * mul * a[i];
    ans = max(ans, mul);
  }

  cout << ans;

  return 0;
}
