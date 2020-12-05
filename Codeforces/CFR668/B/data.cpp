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

const int MAX = 1e5 + 5;
int n;
int a[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    int T;
    cin >> T;
    while(T--) 
    {
        cin >> n;
        vi neg, pos;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (a[i] > 0) pos.push_back(i);
            if (a[i] < 0) neg.push_back(i);
        };

        int u = 0, v = 0;
        while(u < pos.size() && v < neg.size())
        {
            if (pos[u] < neg[v]) {
                int minValue = min(abs(a[pos[u]]), abs(a[neg[v]]));
                a[pos[u]] -= minValue;
                a[neg[v]] += minValue;

                if (a[pos[u]] == 0) ++u;
                if (a[neg[v]] == 0) ++v;
            }
            else ++v;
        }

        ll ans = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] > 0) ans += a[i];
        cout << ans << endl;
    }
    return 0;
}
