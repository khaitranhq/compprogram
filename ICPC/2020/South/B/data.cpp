#include <bits/stdc++.h>
using namespace std;
#define task "data"

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FOD(i, a, b) for (int i = a; i >= b; --i)
#define FRSZ(i, a) for (int i = 0; i < a.size(); ++i)
#define FDSZ(i, a) for (int i = a.size() - 1; i >= 0; --i)
#define debug(x) cout << #x << " = " << x << endl;
#define debugarr(x, n)       \
    {                        \
        FOR(_, 1, n)         \
        cout << x[_] << " "; \
        cout << endl;        \
    }
#define debugvi(x)           \
    {                        \
        FRSZ(_, x)           \
        cout << x[_] << " "; \
        cout << endl;        \
    }
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
int mm, ss, h, m, s, n, k;
string format(int x)
{
    if (x > 10)
    {
        return to_string(x);
    }
    else
    {
        return "0" + to_string(x);
    }
}
int main()
{
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> mm;
        getchar();
        cin >> ss;
        // cout << mm << ' ' << ss << endl;
        s += ss;
        s += mm * 60;
    }
    s -= (n - 1) * k;
    m = s / 60;
    s %= 60;
    h = m / 60;
    m %= 60;
    cout << format(h) << ":" << format(m) << ":" << format(s) << endl;
    return 0;
}
