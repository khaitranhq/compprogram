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
        ll n, s;
        cin >> n >> s;

        int tmp = n;
        vector<int> digit;
        do
        {
            digit.push_back(tmp % 10);
            tmp /= 10;
        } while (tmp);

        int index = -1, sum = 0;
        for (int i = 0; i < digit.size(); ++i)
        {
            sum += digit[i];
            if (sum > s)
                break;
            index = i;
        }

        ll pow = 1;
        if (index == -1)
        {
            for (int i = 0; i < digit.size(); ++i)
                pow *= 10;
            
            cout << pow - n << endl;
        } else
        {
            for (int i = index; i < digit.size(); ++i)
                
        }
        
    }
    return 0;
}
