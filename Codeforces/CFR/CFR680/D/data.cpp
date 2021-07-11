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

const int MAX = 3e5 + 5;
const ll BASE = 998244353;
int n;
ll a[MAX];

ll pow(ll x, ll y) {
  if (!y) return 1;
  ll tmp = pow(x, y / 2);
  if (y % 2) return tmp * tmp % BASE * x % BASE;
  return tmp * tmp % BASE;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    cin >> n;
    for(int i = 1; i <= 2 * n; ++i) cin >> a[i];

    sort(a + 1, a + 2 * n + 1);
    ll delta = 0;
    for (int i = 1; i <= n; ++i)
      delta = (delta + (abs(a[i] - a[n + i]) % BASE)) % BASE; 

    ll gt1 = 1, gt2 = 1, gt3 = 1;
    for (ll i = 1; i <= 2 * n; ++i)
      gt1 = gt1 * i % BASE;

    for (ll i = 1; i <= n; ++i)
      gt2 = gt2 * i % BASE;

    gt3 = gt1 * pow(gt2 * gt2 % BASE, BASE - 2) % BASE;
    
    cout << delta * gt3 % BASE;
    return 0;
}
