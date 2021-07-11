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

typedef int64_t ll;
typedef vector<int> vi;

const int MAX = 105;
bool check[MAX][MAX];
int n, m, x, y;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin >> n >> m >> x >> y;

    int u = x, v = y;
    int cntn = 0, cntm;
    while (1)
    {
        ++cntn;
        cntm = 1;
        cout << u << " " << v << endl;
        check[u][v] = 1;
        while (1)
        {
            int t = -1;
            ++cntm;
            FOR(i, 1, m)
            if (!check[u][i])
            {
                t = i;
                v = i;
                check[u][v] = 1;
                cout << u << " " << t << endl;
                break;
            }

            if (t == -1)
            {
                FOR(i, 1, n)
                if (!check[i][v])
                {
                    u = i;
                    break;
                }
            }
            if (cntm > m)
                break;
        }
        if (cntn == n)
            break;
    }
    return 0;
}
