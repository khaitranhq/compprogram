#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)                 \
    {                                       \
        for (int _ = 0; _ < n; ++_)        \
        {                                   \
            for (int __ = 0; __ < m; ++__) \
                cout << x[_][__] << " ";    \
            cout << endl;                   \
        }                                   \
        cout << endl;                       \
    }
#define debugarr(x, n)               \
    {                                \
        for (int _ = 0; _ < n; ++_) \
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
typedef pair<int, int> ii;

const int MAX = 3e5 + 5;
int n, k;
int a[MAX], sumOne[MAX], sumZero[MAX];

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    int T;
    cin >> T;
    while(T--)
    {
        string s;
        cin >> n >> k;
        cin >> s;

        for (int i = 0; i < n; ++i)
            if (isdigit(s[i]))
                a[i] = s[i] - '0';
            else
                a[i] = -1;

        sumOne[0] = a[0] == 1;
        sumZero[0] = a[0] == 0;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] == 1)
                sumOne[i] = sumOne[i - 1] + 1;
            else
                sumOne[i] = sumOne[i - 1];

            if (a[i] == 0)
                sumZero[i] = sumZero[i - 1] + 1;
            else
                sumZero[i] = sumZero[i - 1];
        }

        bool ans = 1;
        for (int i = k - 1; i < n; ++i)
        {
            if (sumOne[i] - (i > k - 1 ? sumOne[i - k - 1] : 0) > k / 2)
            {
                ans = 0;
                break;
            }

            if (sumZero[i] - (i > k - 1 ? sumZero[i - k - 1] : 0) > k / 2)
            {
                ans = 0;
                break;
            }
        }

        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
