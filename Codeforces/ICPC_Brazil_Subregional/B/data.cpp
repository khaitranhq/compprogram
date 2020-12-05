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
int n;
bool a[MAX][MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
      int d, l, r, c;
      cin >> d >> l >> r >> c;

      if (d == 0)
        for (int j = c; j <= c + l - 1; ++j) {
          if (a[r][j] || j > 10){
            cout << 'N';
            return 0;
          }
          a[r][j] = 1;
        }
      else 
        for (int j = r; j <= r + l - 1; ++j) {
          if (a[j][c] || j > 10) {
            cout << 'N';
            return 0;
          }
          a[j][c] = 1;
        }
    }
    cout << "Y";
    return 0;
}
