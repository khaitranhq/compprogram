#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)          \
    {                                \
        FOR(_, 1, (n))               \
        {                            \
            FOR(__, 1, (m))          \
            cout << x[_][__] << " "; \
            cout << endl;            \
        }                            \
        cout << endl;                \
    }
#define debugarr(x, n)       \
    {                        \
        FOR(_, 1, (n))       \
        cout << x[_] << " "; \
        cout << endl;        \
    }
#define debugvi(x)           \
    {                        \
        FRSZ(_, x)           \
        cout << x[_] << " "; \
        cout << endl;        \
    }

#define fi first
#define se second
#define pb push_back
using namespace std;

typedef int64_t ll;
typedef vector<int> vi;

const int MAX = 2e2 + 5;
int n, m;
int a[MAX], b[MAX];

int getBit(int x, int y)
{
    return ((x >> (y - 1)) & 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int minAnd = 100000;
        for (int j = 1; j <= m; ++j)
        {
            minAnd = min(minAnd, a[i] & b[j]);
        }
        ans |= minAnd;
    }

    cout << ans;
    return 0;
}