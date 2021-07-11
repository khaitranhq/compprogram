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
    while(T--) {
      int n;
      vector<int> b;
      cin >> n;
      for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        b.push_back(x);
      }

      bool flag = 0;
      for (int i = 0; i < b.size() ; ++i)
        for (int j = i + 1; j < b.size(); ++j)
          if (b[i] == b[j]) {
            flag = 1;
            break;
          }
      if (flag) cout << "YES" << endl;
      else cout << "NO" << endl;
    }

    return 0;
}
