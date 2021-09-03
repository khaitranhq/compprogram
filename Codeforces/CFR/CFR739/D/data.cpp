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

const int MAX_LENGTH_DIGITS = 30;
const int INF = 0x3f3f3f3f;
vi powerOf2[MAX_LENGTH_DIGITS];

/*
 *
 */
vi convertNumberToVectorDigits(ll number) {
  vi ans;
  do {
    ans.push_back(number % 10);
    number /= 10;
  } while (number);

  reverse(ans.begin(), ans.end());
  return ans;
}

/*
 * Init all value of 2^x (<= 1e9)
 */
void initPowerOf2() {
  for (int i = 0; i < 60; ++i)
    powerOf2[i] = convertNumberToVectorDigits(1LL << i);
}

/*
 * Find string in power of 2 that has max common digit number
 *
 * @param x: input number
 *
 * @return: number operations min to convert from x to a power of 2
 */
int findMinOperations(ll number) {
  vi formattedNumber = convertNumberToVectorDigits(number);

  int ans = INF;
  for (int i = 0; i < 60; ++i) {
    // u: pointers for power of 2 vectors
    // v: pointers for input number
    // taken: max longest subsequence of input number (string) which is
    // consecutive in power of 2 string
    int u = 0, v = 0, taken = 0;

    while (u < powerOf2[i].size() && v < formattedNumber.size()) {
      if (formattedNumber[v] == powerOf2[i][u]) {
        ++taken;
        ++u;
        ++v;
      } else {
        // Hold u
        // increase v to find same digit
        ++v;
      }
    }

    // If we have `taken` digit same
    // powerOf2[i] must be earsed powerOf2[i].size() - taken
    // formattedNumber must be add formattedNumber.size() - taken
    // So we have this fomula
    int numberOperations =
        powerOf2[i].size() + formattedNumber.size() - 2 * taken;

    ans = min(ans, numberOperations);
  }
  cout << ans << endl;
  return 0;
}

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
  // freopen("data.out", "w", stdout);
#endif

  initPowerOf2();

  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;

    findMinOperations(n);
  }
  return 0;
}
