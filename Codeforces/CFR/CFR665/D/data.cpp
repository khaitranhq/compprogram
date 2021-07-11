#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)                \
    {                                      \
        for (int _ = 0; _ < n; ++_)        \
        {                                  \
            for (int __ = 0; __ < m; ++__) \
                cout << x[_][__] << " ";   \
            cout << endl;                  \
        }                                  \
        cout << endl;                      \
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
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAX = 1e5 + 5;
const int BASE = 1e9 + 7;

int n, m;
vi adj[MAX];
int p[MAX], numChild[MAX], par[MAX];
bool check[MAX];
vector<int> res;

void DFS(int u)
{
    check[u] = 1;
    numChild[u] = 1;
    for (int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i];
        if (check[v])
            continue;
        par[v] = u;
        DFS(v);
        numChild[u] += numChild[v];
    }
}

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

        for (int i = 0; i < n - 1; ++i)
            adj[i].clear();

        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cin >> m;
        for (int i = 0; i < m; ++i)
            cin >> p[i];

        vi edgeCost;
        sort(p, p + m, greater<int>());
        for (int i = 0; i < m; ++i)
            if (edgeCost.size() < n - 1)
                edgeCost.push_back(p[i]);
            else
            {
                edgeCost[i % (n - 1)] = 1LL * edgeCost[i % (n - 1)] * p[i] % BASE;
            }

        while (edgeCost.size() < n - 1)
            edgeCost.push_back(1);

        memset(check, 0, sizeof(check));
        DFS(0);

        res.clear();
        queue<int> q;
        memset(check, 0, sizeof(check));
        q.push(0);
        check[0] = 1;
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < adj[u].size(); ++i)
            {
                int v = adj[u][i];
                if (!check[v])
                {
                    q.push(v);
                    res.push_back(1LL * numChild[v] * (numChild[0] - numChild[v]) % BASE);
                    check[v] = 1;
                }
            }
        }

        sort(res.begin(), res.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < res.size(); ++i)
            ans = (ans + 1LL * res[i] * edgeCost[i] % BASE) % BASE;
        cout << ans << endl;
    }
    return 0;
}
