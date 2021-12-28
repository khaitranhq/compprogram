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

int main() {

  int T;
  cin >> T;
  while (T--) {
    vector<int> a;
    for (int i = 0; i < 3; ++i) {
      int x;
      cin >> x;
      a.push_back(x);
    }
    sort(a.begin(), a.end());

    if (a.back() == a[0] + a[1] || (a[0] == a[1] && a[2] % 2 == 0) ||
        (a[0] == a[2] && a[1] % 2 == 0) || (a[1] == a[2] && a[0] % 2 == 0))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
