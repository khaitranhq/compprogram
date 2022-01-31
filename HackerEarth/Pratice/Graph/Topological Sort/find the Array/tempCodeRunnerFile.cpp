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

const int MAX = 1e5 + 5;
int n, m;
int b[MAX];
vi adj[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--) 
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            cin >> b[i];
        
        for (int i = 1; i <= m; ++i)
        {
            string s;
            cin >> s;
            
            int u = 0, v = 0;
            bool isU = true, isGreater = true;
            for (auto ch : s)
            {
                debug(ch);
                if (ch == '<' || ch == '>') isU = false;
                if (isdigit(ch))
                    if (isU)
                        u = u * 10 + ch - '0';
                    else
                        v = v * 10 + ch - '0';
                
                if (ch == '<') isGreater = false;
            }
            debug(i);
            debug(u); debug(v); cout << endl;

            if (isGreater) adj[u].push_back(v);
            else adj[v].push_back(u);
        }
        
        for (int i = 1; i <= n; ++i) 
        {
            for (auto j: adj[i])
                cout << j << " ";
            cout << endl;
        }
    }

    return 0;
}