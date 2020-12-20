#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll nax = 1e6 + 7, inf = 1e18;

ll dishc[nax], dissc[nax], dishi[nax], dissi[nax];
int hc, sc, hi, si;
int n, m;

vector <pll> edge[nax];
vector <pair<pair<ll, ll> , ll>> ee;

void disss(ll start, ll dis[], int n)
{
    priority_queue<pll, vector <pll>, greater<pll>> q;
    vector <bool> vis(n + 1, 0);
    q.push({0, start});
    dis[start] = 0;
    while (q.size())
    {
        auto p = q.top();
        q.pop();
        ll x = p.second, d = p.first;
        if (vis[x]) continue;
        vis[x] = 1;
        for (auto it : edge[x])
        {
            auto e = it.first;
            auto w = it.second;
            if (dis[e] > dis[x] + w)
            {
                dis[e] = dis[x] + w;
                q.push({dis[e], e});
            }

        }
    }
}

int calc (pair<pll, ll> x)
{

    int res = 0;
    int a = x.first.first, b = x.first.second, c = x.second;

    ll xx = -1;


    if (dishc[a] + dissc[b] + c == dishc[sc])
    {
        if (dishi[a] + dissi[b] + c == dishi[si])
        {
            if (dishi[a] == dishc[a]) return -1;
        }
        if (dishi[b] + dissi[a] + c == dishi[si])
        {
            ll aa = dishc[a], bb = dishi[b];
            ll xx1 = aa - bb + c;
            if (xx1 > 0 && xx1 < 2 * c)
            {
                xx = xx1;
                res++;
            }

            //cout << dishc[a] << " " << dissc[b] << "\n";
            //cout << xx1 << "\n";
        }
    }

    if (dishc[b] + dissc[a] + c == dishc[sc])
    {
        if (dishi[b] + dissi[a] + c == dishi[si])
        {
            if (dishi[b] == dishc[b]) return -1;
        }
        if (dishi[a] + dissi[b] + c == dishi[si])
        {
            ll aa = dishi[a], bb = dishc[b];
            ll xx1 = aa - bb + c;
            if (xx1 > 0 && xx1 < 2 * c)
            {
                if (xx1 != xx)
                {
                    xx = xx1;
                    res++;
                }
            }
            //cout << dishi[a] << " " << dissi[b] << "\n";
            //cout << xx1 << "\n";
        }
    }
    return res;
}

bool solve()
{

    cin >> n >> m;

    if (n == 0 || m == 0) return false;

    for (int i = 1 ; i <= n; ++i)
    {
        dishc[i] = dissc[i] = dishi[i] = dissi[i] = inf;
        edge[i].clear();
    }

    ee.clear();

    cin >> hc >> sc >> hi >> si;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
        ee.push_back(make_pair(make_pair(a, b), c));
    }

    disss(hc, dishc, n);
    disss(sc, dissc, n);
    disss(hi, dishi, n);
    disss(si, dissi, n);

    /*for (int i = 1; i <= n; ++i)
        cout << dishc[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; ++i)
        cout << dissc[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; ++i)
        cout << dishi[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; ++i)
        cout << dissi[i] << " ";
    cout << "\n";
    */

    bool flagsi = false, flagsc = false;
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (dishc[i] + dissc[i] != dishc[sc] || dishi[i] + dissi[i] != dishi[si]) continue;
        if (dishc[i] == dishi[i])
        {
            res++;
            if (i == si) flagsi = true;
            if (i == sc) flagsc = true;
        }
    }

    if (!flagsi)
    {
        if (dissc[si] + dishc[si] == dishc[sc])
        {
            if (dishi[si] <= dishc[si]){
            if (si == sc) flagsc = true;
            res++;
            }
        }


    }

    if (!flagsc)
    {
        if (dissi[sc] + dishi[sc] == dishi[si])
        {
            if (dishc[sc] <= dishi[sc]) res++;
        }
    }

    for (int i = 0; i < m; ++i)
    {
        if (calc(ee[i]) != -1)
            res += calc(ee[i]);
        else
        {
            cout << -1 << "\n";
            return true;
        }
        
    }

    cout << res << "\n";
    return true;

}
int main(){
    //freopen("input.inp", "r", stdin);
    while(solve());

}
