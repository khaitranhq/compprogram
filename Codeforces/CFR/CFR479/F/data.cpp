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

const int MAX = 2e5 + 5;
int n;
int a[MAX];

void enter() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
}

void solve() {
  map<int, int> dp;
  for (int i = 1; i <= n; ++i) {
    if (!dp.count(a[i]))
      dp[a[i]] = 0;

    if (dp.count(a[i] - 1))
      dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);
  }

  int lastValueIndex = 0;
  for (int i = 1; i <= n; ++i)
    if (!lastValueIndex || dp[a[lastValueIndex]] < dp[a[i]])
      lastValueIndex = i;

  cout << dp[a[lastValueIndex]] + 1 << endl;

  vector<int> subsequenceIndex;
  subsequenceIndex.push_back(lastValueIndex);
  for (int i = n; i >= 1; --i)
    if (a[i] == a[lastValueIndex] - 1 && i < lastValueIndex) {
      subsequenceIndex.push_back(i);
      lastValueIndex = i;
    }

  reverse(subsequenceIndex.begin(), subsequenceIndex.end());
  for (int i = 0; i < subsequenceIndex.size(); ++i)
    cout << subsequenceIndex[i] << " ";
}

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
#endif

  enter();
  solve();
  return 0;
}
