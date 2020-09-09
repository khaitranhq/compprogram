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

typedef long long ll;
typedef vector<int> vi;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--) 
    {
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;

        if (max(a - n, x) < max(b - n, y)){
            ll a1 = max(a - n, x);
            ll b1 = max(b - (n - a + a1), y);
            cout << a1 * b1 << endl;
        }
        else {
            ll b1 = max(b - n, y);
            ll a1 = max(a - (n - b + b1), x);
            cout << a1 * b1 << endl;
        }
    }
    return 0;
}
