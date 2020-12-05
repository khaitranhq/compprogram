
#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)                 \
    {                                       \
        for (int _ = 0; _ < n; ++_)        \
        {                                   \
            for (int __ = 0; __ < m; ++__) \
                cout << x[_][__] << " ";    \
            cout << endl;                   \
        }                                   \
        cout << endl;                       \
    }
#define debugarr(x, n)               \
    {                                \
        for (int _ = 0; _ < n; ++_) \
            cout << x[_] << " ";     \
        cout << endl;                \
    }
#define debugvi(x)                         \
    {                                      \
        for (int _ = 0; _ < x.size(); ++_) \
            cout << x[_] << " ";           \
        cout << endl;                      \
    }

#define fi first
#define se second
#define pb push_back
using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t){
      int n;
      cin >> n;

      cout << "Case #" << t << ": ";
      
      int ans = 100000000;
      for (int i = 2; i <= n; ++i)
          if (__gcd(i, n - i) == 1)
            ans = min(ans, max(n, n - i) - min(n, n - i));

      for (int i = 2; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
          if (i + j < n && __gcd(i, j) == 1 && __gcd(i, n - i - j) == 1 && __gcd(j, n - i - j))
            ans = min(ans, max(i, max(j, n - i - j)) - min(i, min(j, n- i - j)));
      cout << ans << endl;
    }
    return 0;
}
