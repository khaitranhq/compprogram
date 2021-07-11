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

int gcd(int x, int y)
{
    if (!y)
        return x;
    return gcd(y, x % y);
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
        int n, x, y;
        cin >> n >> x >> y;

        int diff;
        for (int i = 1; i <= y - x; ++i)
            if ((y - x) % i == 0 && (y - x) / i + 1 <= n)
            {
                diff = i;
                break;
            }

        deque<int> dq;
        for (int i = x; i <= y && dq.size() < n; i += diff)
            dq.push_back(i);

        for (int i = x - diff; i > 0 && dq.size() < n; i -= diff)
            dq.push_front(i);

        for (int i = y + diff; dq.size() < n; i += diff)
            dq.push_back(i);

        while (dq.size())
        {
            cout << dq.back() << " ";
            dq.pop_back();
        }
        cout << endl;
    }
    return 0;
}
