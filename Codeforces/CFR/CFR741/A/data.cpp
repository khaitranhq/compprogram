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

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
#endif

  int T;
  cin >> T;
  while(T--) {
    int l, r;
    cin >> l >> r;

    int mid = r / 2 + 1;

    if (mid < l) cout << r % l << endl;
    else cout << r % mid << endl;

    int a = "d";
  }
  return 0;
}
