#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)                \
{                                      \
  for (int _ = 0; _ < n; ++_)        \
  {                                  \
    for (int __ = 0; __ < m; ++__) \
    cout << x[_][__] << " ";   \
    cout << endl;                  \
  }                                  \
  cout << endl;                      \
}
#define debugarr(x, n)              \
{                               \
  for (int _ = 0; _ < n; ++_) \
  cout << x[_] << " ";    \
  cout << endl;               \
}
#define debugvi(x)                         \
{                                      \
  for (int _ = 0; _ < x.size(); ++_) \
  cout << x[_] << " ";           \
  cout << endl;                      \
}

#define fi first
#define se second
#define pb push_back
using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll p, f;
ll cnts, cntw;
ll s, w;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--)
  {

    cin >> p >> f;
    cin >> cnts >> cntw;
    cin >> s >> w;

    ll ans = 0;
    for (int u = 0; u <= cnts && u * s <= p; ++u){
      ll v = max(0LL, (p - u * s) / w);
      int x, y;
      if (s < w) {
        x = min(cnts - u, f / s);
        y = min(cntw - v, (f - x * s) / w);
      } else {
        y = min(cntw - v, f / w);
        x = min(cnts - u, (f - y * w) / s);
      }
      ans = max(ans, u + v + x + y);                
    }
    cout << ans << endl;
  }
  return 0;
}
