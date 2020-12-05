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
    while(T--){
      int a, b;
      string s;
      cin >> a >> b;
      cin >> s;

      vector<int> numZero;
      int numOneBlock = 0;
      bool metOne = 0;
      int cnt = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1' && (i == 0 || s[i - 1] == '0')) ++numOneBlock;
        if (s[i] == '1' && !metOne) metOne = 1;
        if (s[i] == '0' && metOne) ++cnt;
        if (cnt && s[i] == '1') {
          numZero.push_back(cnt);
          cnt = 0;
        }
      }

      sort(numZero.begin(), numZero.end()); 
    
      int ans = numOneBlock * a;
      for (int i = 0; i < numZero.size(); ++i)
        if (numZero[i] * b < a) ans += numZero[i] * b - a;

      cout << ans << endl;
    }

    return 0;
}
