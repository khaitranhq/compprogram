#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define EPS 1e-9
const ll nx = 3e5, mx = 5e5;
ll indeg[nx], outdeg[nx];
vector<ll> adj[nx];
double ways[mx];
int main()
{
    ll n, m, r;
    cin >> n >> m >> r;
    assert(n <= nx && m <= mx && r <= n);
    --r;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        indeg[v]++, outdeg[u]++;
    }
    ways[r] = 1;
    queue<ll> q;
    for (ll i = 0; i < n; i++)
        if (indeg[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        ll a = q.front();
        q.pop();
        for (auto i : adj[a])
        {
            ways[i] += ways[a] * 1.0 / outdeg[a];
            indeg[i]--;
            if (indeg[i] == 0)
                q.push(i);
        }
    }
    double mx = 0;
    int idx = 0;
    for (int i = 0; i < n; i++)
        if (outdeg[i] == 0 && ways[i] > mx)
            mx = max(mx, ways[i]);
    for (ll i = 0; i < n; i++)
        if (outdeg[i] == 0 && abs(ways[i] - mx) <= EPS)
            cout << i + 1 << ' ';
    cout << "\n";
}