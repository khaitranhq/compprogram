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

int n;

/*
 * Init all value of 2^x (<= 1e9)
 */
void initPowerOf2() {}

/*
 * Find string in power of 2 that has max common digit number
 *
 * @param x: compared string
 *
 * @return: string has max common digit number with param string
 */
string findMaxCommonDigitString(string x) { return ""; }

/*
 * Find number of operations to convert string x to string y
 *
 * @param x: source string
 * @param y: target string
 *
 * @return number of operations
 */
int processNumber(string x, string y) {
  return 0;
}

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  initPowerOf2();

  int T;
  cin >> T;
  while (T--) {
    cin >> n;
  }
  return 0;
}
