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
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAX = 2e5 + 5;
const double EPS = 1e-9;
int n, m, r;
vector<int> adj[MAX];
int inDeg[MAX], outDeg[MAX];
double prob[MAX];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    memset(inDeg, 0, sizeof(inDeg));
    memset(outDeg, 0, sizeof(outDeg));

    cin >> n >> m >> r;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        ++inDeg[v]; ++outDeg[u];
    }

    queue<int> q;
    memset(prob, 0, sizeof(prob));
    prob[r] = 1;
    
    for (int i = 1; i <= n; ++i)
        if (!inDeg[i])
            q.push(i);

    while(q.size())
    {
        int u = q.front(); q.pop();
        for (auto v: adj[u])
        {
            prob[v] += prob[u] * 1.0 / outDeg[u];
            --inDeg[v];
            if (!inDeg[v])
                q.push(v);
        }
    }

    double maxProb = 0;
    for (int i = 1; i <= n; ++i)
        if (prob[i] > maxProb && !outDeg[i])
            maxProb = prob[i];
    
    for (int i = 1; i <= n; ++i)
        if (abs(maxProb - prob[i]) <= EPS && !outDeg[i])
            cout << i << ' ';
    return 0;
}