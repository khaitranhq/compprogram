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

typedef int64_t ll;
const int MAX = 1e5 + 5;
ll dp[MAX];

int main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    memset(dp, 0, sizeof(dp));

    map<char, pair<int,int> > mp;

    dp[1] = 1;
    mp[s[1]] = {0, 1};
    for (int i = 2; i <= n; ++i) {
      dp[i] = dp[i - 1];
      if (!mp.count(s[i])) {
        dp[i] += i * 1LL;
        mp[s[i]] = {0, i};
      } else {
        dp[i] += (ll)(i - mp[s[i]].second - (mp[s[i]].second - mp[s[i]].first));
        mp[s[i]] = {mp[s[i]].second, i};
      }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
      ans += dp[i];
    cout << ans << endl;
  }
  return 0;
}
