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

int cnt[27];

int main() {
/*   freopen("data.inp", "r", stdin); */
  /* freopen("data.ans", "w", stdout); */
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < s.size(); ++i)
      for (int j = i; j < s.size(); ++j) {
        memset(cnt, 0, sizeof(cnt));
        for (int k = i; k <= j; ++k)
          cnt[s[k] - 'a']++;
        for (int k = 'a'; k <= 'z'; ++k)
          ans += cnt[k - 'a'] == 1;
      }
    cout << ans << endl;
  }
  return 0;
}
