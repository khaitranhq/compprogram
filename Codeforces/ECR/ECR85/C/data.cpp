#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FOD(i, a, b) for (int i = a; i >= b; --i)
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define FRSZ(i, a) for (int i = 0; i < a.size(); ++i)
#define FDSZ(i, a) for (int i = a.size() – 1; i >= 0; --i)

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)              \
    {                                    \
        FOR(_, 1, (n))                   \
        {                                \
            FOR(__, 1, (m))              \
                cout << x[_][__] << " "; \
            cout << endl;                \
        }                                \
        cout << endl;                    \
    }
#define debugarr(x, n)           \
    {                            \
        FOR(_, 1, (n))           \
            cout << x[_] << " "; \
        cout << endl;            \
    }
#define debugvi(x)               \
    {                            \
        FRSZ(_, x)               \
            cout << x[_] << " "; \
        cout << endl;            \
    }

#define fi first
#define se second
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
const int MAX = 3e5 + 5;
int n;
ii a[MAX];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i].fi >> a[i].se;

        ll ans = 0;
        for (int i = 0; i < n; ++i)
            if (i == 0 || a[i - 1].se - a[i].fi < 0)
                ans += a[i].fi - a[i - 1].se;

        for (int i = 0; i < n; ++i)
        {
            int k = (i - 2 + n) % n;
            int j = (i - 1 + n) % n;
            ans += min(0LL, a[i].fi - a[j].fi + max(0LL, a[j].fi - a[k].se));
        }
        cout << ans << endl;
    }
    return 0;
}
