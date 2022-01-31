#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[8];
ll f(const vector<ll> &a, const vector<ll> &b, const vector<ll> &c)
{
    ll x1 = b[0] - a[0], y1 = b[1] - a[1], x2 = c[0] - b[0], y2 = c[1] - b[1];
    return x1 * y2 - y1 * x2;
}
bool isConvex(vector<vector<ll>> &polls)
{
    ll sz = polls.size(), i = 0, init = 0, curr = 0;
    if (sz < 3)
    {
        return false;
    }
    for (i = 0; i < sz; ++i)
    {
        curr = f(polls[i % sz], polls[(i + 1) % sz], polls[(i + 2) % sz]);
        if (curr)
        {
            if (init == 0)
            {
                init = curr;
            }
            else if ((init < 0 and curr > 0) or (init > 0 and curr < 0))
            {
                return false;
            }
        }
    }
    return init;
}
int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        vector<vector<ll>> polls;
        vector<ll> tmp;
        polls.clear();
        for (ll i = 0; i < 8; i++)
            cin >> a[i];
        for (ll i = 0; i < 8; i += 2)
        {
            tmp.clear();
            tmp.push_back(a[i]);
            tmp.push_back(a[i + 1]);
            polls.push_back(tmp);
        }
        if (isConvex(polls))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
