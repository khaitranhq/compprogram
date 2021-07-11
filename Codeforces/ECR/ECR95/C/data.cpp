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

const int MAX = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int n;
int a[MAX];
int f[MAX][2];

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
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        memset(f, INF, sizeof(f));

        f[0][1] = a[0];
        f[1][1] = a[0] + a[1];
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < 2; ++j)
            {
                if (i == 1 && j == 1) continue;
                f[i][j] = f[i - 1][j ^ 1] + (a[i] && j);
                if (i > 1)
                    f[i][j] = min(f[i][j], f[i - 2][j ^ 1] + (a[i] && j) + (a[i - 1] && j));

                // debug(i);
                // debug(j);
                // debug(f[i][j]);
            }
        
        cout << min(f[n - 1][0], f[n - 1][1]) << endl;
    }
    return 0;
}
