#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)                                                    \
  {                                                                            \
    FOR(_, 1, (n)) {                                                           \
      FOR(__, 1, (m)) cout << x[_][__] << " ";                                 \
      cout << endl;                                                            \
    }                                                                          \
    cout << endl;                                                              \
  }
#define debugarr(x, n)                                                         \
  {                                                                            \
    FOR(_, 1, (n)) cout << x[_] << " ";                                        \
    cout << endl;                                                              \
  }
#define debugvi(x)                                                             \
  {                                                                            \
    FRSZ(_, x) cout << x[_] << " ";                                            \
    cout << endl;                                                              \
  }

#define left first
#define right second
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
const int MAX_NUMBER_ARRAY_ELEMENTS = 2e5 + 5;
const int MIN_VALUE = -1e9;

ii a[MAX_NUMBER_ARRAY_ELEMENTS];
int n;
unordered_map<int, int> dpResult[MAX_NUMBER_ARRAY_ELEMENTS][5];

void readInput() {
  memset(a, 0, sizeof(a));
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    dpResult[i][0].clear();
    dpResult[i][1].clear();
    cin >> a[i].left >> a[i].right;
  }
}

/*
 * Dynamic Programming with Memorization
 * Maximum union of segments from i to n with the maxEndpointPos
 *
 * @param i: index in array a
 * @param maxEndpointPos: max coordiante of the end points of considered
 * segements so far
 * @param isDeleted: deleted a segment or not yet
 */
int dp(int i, int maxEndpointPos, bool isDeleted) {
  if (i == n) {
    if (!isDeleted)
      return MIN_VALUE;
    return 1;
  }

  // If this stated was calculated
  if (dpResult[i][isDeleted].count(maxEndpointPos))
    return dpResult[i][isDeleted][maxEndpointPos];

  int bonus = (a[i + 1].left > maxEndpointPos);

  // If isDeleted = 1 => only solve child state with isDeleted = 1
  int ans = dp(i + 1, max(maxEndpointPos, a[i + 1].right), isDeleted) + bonus;

  // If isDeleted = 0 => isDeleted of child state can be 0 or 1
  if (!isDeleted) {
    ans = max(ans, dp(i + 1, maxEndpointPos, 1));
  }
  dpResult[i][isDeleted][maxEndpointPos] = ans;
  printf("%d %d %d => %d\n", i, maxEndpointPos, isDeleted, ans);
  return ans;
}

void solve() {
  sort(a + 1, a + n + 1);
  dp(1, a[1].right, 0);
}

int main() {
#ifdef LOCAL
  freopen("input.2", "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
    readInput();
    solve();
  }
  return 0;
}
