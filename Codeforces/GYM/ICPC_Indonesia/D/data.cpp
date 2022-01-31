#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)                 \
    {                                       \
        for (int _ = 1; _ <= n; ++_)        \
        {                                   \
            for (int __ = 1; __ <= m; ++__) \
                cout << x[_][__] << " ";    \
            cout << endl;                   \
        }                                   \
        cout << endl;                       \
    }
#define debugarr(x, n)              \
    {                               \
        for (int _ = 0; _ < n; ++_) \
            cout << x[_] << " ";    \
        cout << endl;               \
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

const int MAX = 2 * 1e3;
const int BASE = 1e9 + 7;
int n, m, r;
int x[MAX], y[MAX], a[MAX];
int c[MAX][MAX];
int sumAdj[MAX];
int f[MAX][MAX], g[MAX][MAX];
vector<int> adj[MAX];

int pow2(int x)
{
    return 1ll * x * x % BASE;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin >> n >> m >> r;

    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i] >> a[i];

    //Calc nCk

    for (int i = 0; i <= n; ++i)
    {
        c[i][0] = 1;
        c[i][i] = 1;
    }

    for (int i = 2; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % BASE;

    // Find adj vertices
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            if (abs(x[i] - x[j]) <= r && abs(y[i] - y[j]) <= r)
            {
                adj[i].push_back(j);
                sumAdj[i] += a[j];
            }

    // Calc sum
    memset(g, 0, sizeof(g));

    for (int i = 1; i <= m; ++i)
        g[i][i] = (g[i - 1][i - 1] + a[i]) % BASE;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m && j < i; ++j)
        {
            g[i][j] = (1LL * a[i] * ((c[i - 1][j] - c[i - 1 - adj[i].size()][j] + BASE) % BASE) % BASE + g[i - 1][j]) % BASE;

            g[i][j] = (g[i][j] + (((j == 1 ? sumAdj[i] : 0) + a[i]) % BASE * 1LL * c[i - 1][j - 1] % BASE + g[i - 1][j - 1]) % BASE) % BASE;
        }

    for (int i = 1; i <= m; ++i)
        f[i][i] = 1LL * g[i][i] * g[i][i] % BASE;
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m && j < i; ++j)
        {
            f[i][j] = (f[i - 1][j] + 1LL * pow2(a[i]) * 1LL * ((c[i - 1][j] - c[i - 1 - adj[i].size()][j] + BASE) % BASE) % BASE) % BASE;
            f[i][j] = (f[i][j] + 2LL * a[i] * g[i - 1][j] % BASE);

            if (i == 3 && j == 1)
            {
                debug((c[i - 1][j] - c[i - 1 - adj[i].size()][j] + BASE) % BASE);
                debug(f[i][j]);
            }

            f[i][j] = (f[i][j] + pow2(((j == 1 ? sumAdj[i] : 0) + a[i]) % BASE) * 1LL * c[i - 1][j - 1] % BASE) % BASE;
            f[i][j] = (f[i][j] + f[i - 1][j - 1]) % BASE;
            f[i][j] = (f[i][j] + 2LL * ((j == 1 ? sumAdj[i] : 0) + a[i]) % BASE * g[i - 1][j - 1]);
        }
    debugarr2d(f, n, m);
    return 0;
}
