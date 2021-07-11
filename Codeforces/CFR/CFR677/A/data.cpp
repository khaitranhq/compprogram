#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)                 \
{                                       \
  for (int _ = 0; _ < n; ++_)        \
  {                                   \
    for (int __ = 0; __ < m; ++__) \
    cout << x[_][__] << " ";    \
    cout << endl;                   \
  }                                   \
  cout << endl;                       \
}
#define debugarr(x, n)               \
{                                \
  for (int _ = 0; _ < n; ++_) \
  cout << x[_] << " ";     \
  cout << endl;                \
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

typedef int64_t ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  int T;
  cin >> T;
  while(T--)
  {
    int x;
    cin >> x;
    debug(x);
    int ans = 0;
    for (int i = 1; i <= 9; ++i)
    {
      int u = 0;
      for (int j = 0; j <= 3; ++j)
      {
        u = u * 10 * (j > 0)+ i;
        if (u <= x) {
          cout << u << endl;
          ans += j + 1;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
