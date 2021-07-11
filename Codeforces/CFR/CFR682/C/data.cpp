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

const int MAX = 1e2 + 5;
int n, m;
int a[MAX][MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--) {
      cin >> n >> m;
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m;  ++j) 
          cin >> a[i][j];

      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          bool isOdd = 1;
          if (((i % 2 == 0) ^ (j % 2 == 0)) == 1)
            isOdd = 1;
          else isOdd = false;

          if (isOdd){
            if (a[i][j] % 2 == 0) ++a[i][j];
          }
          else 
            if (a[i][j] % 2 == 1) ++a[i][j];

          cout << a[i][j] << " ";
        }
        cout << endl;
      }
    }

    return 0;
}
