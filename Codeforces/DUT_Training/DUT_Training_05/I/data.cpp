#include <bits/stdc++.h>
#include <bitset>

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
typedef vector<bool> vb;
typedef pair<int, int> pii;

vb convertDec2Bin(ll x) {
  vb ans;
  do {
    ans.push_back(x % 2);
    x /= 2;

  } while (x);
  return ans;
}

void solve() {
  ll a, b;
  cin >> a >> b;

  vb binA = convertDec2Bin(a), binB = convertDec2Bin(b);

  while (binA.size() < max(binA.size(), binB.size()))
    binA.push_back(0);
  while (binB.size() < max(binA.size(), binB.size()))
    binB.push_back(0);

  // debugvi(binA);
  // debugvi(binB);

  ll ans = 0;
  bool flag = 1;
  for (int i = 0; i < max(binA.size(), binB.size()); ++i) {
    // debug(i); debug(binA[i]);debug(binB[i]);
    if (!binA[i] && binB[i]) {
      flag = 0;
      break;
    }
    if (binA[i] && !binB[i])
      ans += (1LL << i);
  }

  // debugvi(convertDec2Bin(ans));

  if (!flag)
    cout << -1 << endl;
  else
    cout << ans << endl;
}

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
