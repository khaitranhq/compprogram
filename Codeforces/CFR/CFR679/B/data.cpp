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

const int MAX = 505;
int n, m;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--){
      cin >> n >> m;
      vector<vi> a;
      for (int i = 1; i <= n; ++i) {
        vi tmp;
        for (int j = 1; j <= m; ++j) {
          int x;
          cin >> x;
          tmp.push_back(x);
        }
        a.push_back(tmp);
      }

      vi firstCol;
      bool found = 0;
      for (int j = 1; j <= m; ++j)
      {
        for (int i = 1; i <= n; ++i)
        {
          int x;
          cin >> x;
          if (found) continue;
          firstCol.push_back(x);
        }

        if (found) continue;
        for (int i = 0; i < firstCol.size(); ++i)
          if (firstCol[i] == a[0][0]) {
            found = 1;
            break;
          }
      }


      for (int i = 0 ; i < firstCol.size(); ++i) {
        for (int j = 0 ; j < a.size(); ++j)
          if (a[j][0] == firstCol[i]) {
            for (int k = 0; k < a[j].size(); ++k) cout << a[j][k] << " ";
            cout << endl;
            break;
          }
      }
    }

    return 0;
}
