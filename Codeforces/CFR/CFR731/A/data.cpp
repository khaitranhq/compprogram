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

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  int T;
  cin >> T;
  while(T--) {
    int xA, yA, xB, yB, xF, yF;
    cin >> xA >> yA >> xB >> yB >> xF >> yF;

    int tmp = abs(xB - xA) + abs(yB-yA);
    if (xA == xB && xB == xF)
      if (yA < yF && yF < yB)
        tmp += 2;
      else
        if (yA > yF && yF > yB)
          tmp += 2;
    if (yA == yB && yB == yF)
      if (xA < xF && xF < xB)
      tmp += 2;
      else
      if (xA > xF && xF > xB)
        tmp += 2;

    cout << tmp << endl;

  }

  return 0;
}
