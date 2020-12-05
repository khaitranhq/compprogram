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
#define debugarr(x, n)               \
    {                                \
        for (int _ = 1; _ <= n; ++_) \
            cout << x[_] << " ";     \
        cout << endl;                \
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

const int MAX = 1e5 + 5;
int n, a[MAX];

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
        int minNumber = 1E9 + 5;
        vi b;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            minNumber = min(minNumber, a[i]);
        }

        for (int i = 1; i <= n; ++i)
            if (a[i] % minNumber == 0)
                b.push_back(a[i]);

        sort(b.begin(), b.end(), greater<int>());

        for (int i = 1; i <= n; ++i)
            if (a[i] % minNumber == 0)
            {
                a[i] = b.back();
                b.pop_back();
            }

        bool ans = true;
        for (int i = 2; i <= n; ++i)
            if (a[i] < a[i - 1])
            {
                ans = false;
                break;
            }

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
