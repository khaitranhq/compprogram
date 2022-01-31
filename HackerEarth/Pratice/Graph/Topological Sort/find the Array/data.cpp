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
typedef pair<int, int> ii;

const int MAX = 1e5 + 5;
int n, m;
int b[MAX];
vi adj[MAX];
bool isVisited[MAX];

void enterVertices(int &ver)
{
    char ch;
    do
    {
        ch = getchar();
    } while (!isdigit(ch));

    do
    {
        ver = ver * 10 + ch - '0';
        ch = getchar();
    } while (isdigit(ch));
}

bool checkDag(int u)
{
    bool ans = true;
    isVisited[u] = true;
    for (auto v : adj[u])
    {
        if (!isVisited[v])
            ans &= checkDag(v);
        else
        {
            ans = false;
            break;
        }
    }
    return ans;
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
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            cin >> b[i];

        char tmp;

        for (int i = 1; i <= m; ++i)
        {
            int u = 0, v = 0;
            bool isGreater = true;

            enterVertices(u);

            char ch;
            do
            {
                ch = getchar();
            } while (ch != '>' && ch != '<');

            if (ch == '<')
                isGreater = false;

            enterVertices(v);

            if (isGreater)
                adj[u].push_back(v);
            else
                adj[v].push_back(u);
        }

        
    }

    return 0;
}