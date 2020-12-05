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

const int MAXN = 55, MAXX = 1005;
int n, x;
int a[MAXN], b[MAXN];
int num[MAXX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--) {
      cin >> n >> x;

      memset(num, 0, sizeof(num));
      for (int i = 1; i <= n; ++i) cin >> a[i];
      for (int i = 1; i <= n; ++i) {
        cin >> b[i];
      }

      bool ans = 1;
      for (int i = 1; i <= n; ++i)
        if (a[i] + b[n - i + 1] > x) {
          ans = 0;
        }
      if (ans) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    return 0;
}
