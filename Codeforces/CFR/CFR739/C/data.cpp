#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
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

pii findPosition(int layerNumber, int remain) {
  if (remain == 0)
    return {layerNumber - 1, 1};

  int numbersInLayer = 2 * layerNumber - 1;
//   debug(numbersInLayer);
//   debug(remain);
  if (2 * remain < numbersInLayer)
    return {remain, layerNumber};

  // debug("Case 3");
  return {layerNumber, numbersInLayer - remain + 1};
}

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    int k;
    cin >> k;

    int layerNumber = sqrt(k);
    // debug(layerNumber);

    pii ans = findPosition(layerNumber + 1, k - layerNumber * layerNumber);
    cout << ans.first << " " << ans.second << endl;
  }

  return 0;
}
