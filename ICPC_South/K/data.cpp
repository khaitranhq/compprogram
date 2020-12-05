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
#define pi acos(-1.L)
using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAX = 102;
double t;
int n;
ii a[MAX];


bool cmp(ii x, ii y){
  return x.se < y.se;
}

int main(){

    cin >> t;
    cin >> n;
    for (int i = 1; i <= n; ++i) 
      cin >> a[i].fi >> a[i].se;

    sort(a + 1, a + n + 1, cmp);

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
      int cnt = min(a[i].fi, (int)(t / (2 * a[i].se * pi)));
      t -= cnt * 2 * pi * a[i].se;
      ans += cnt;
    }

    cout << ans;
    return 0;
}
