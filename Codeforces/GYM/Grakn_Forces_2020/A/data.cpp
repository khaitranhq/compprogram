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

const int MAX = 1e2 + 5;
int n;
int a[MAX], b[MAX], c[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) cin >> c[i];

        vector<int> ans;
        ans.push_back(a[1]);

        for (int i = 2; i < n; ++i)
        {
            if (a[i] != ans.back()) {
                ans.push_back(a[i]);
                continue;
            }

            if (b[i] != ans.back()) {
                ans.push_back(b[i]);
                continue;
            }

            if (c[i] != ans.back()) {
                ans.push_back(c[i]);
                continue;
            }
        }

            if (a[0] != ans.back()) {
                cout << a[0] <<  " ";
            }

            else if (b[0] != ans.back()) {
                cout << b[0] << " ";
            }

            else if (c[0] != ans.back()) {
                cout << c[0] << " ";
            }


        for (int i = 0; i < ans.size(); ++i)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
