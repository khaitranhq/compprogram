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
    int n, c, b;
    int z[500005];
    int cnt = 0;
    int main()
    {
    #ifndef ONLINE_JUDGE
        freopen("data.inp", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
        cin >> n >> c >> b;
        vector<int> a;
        string s = string(n, '1');
        for (int i = 1; i <= b; i++)
        {
            cin >> z[i];
            s[z[i] - 1] = '0';
        }
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                cnt++;
            }
        }
        if (cnt == c)
        {
            cout << s << endl;
            return 0;
        }
        if (cnt > c)
        {
            c = cnt - c;
            if (c % 2 == 1)
            {
                s[0] = '0';
                if (s[1] == '1')
                {
                    c++;
                }
                else
                {
                    c--;
                }
            }
            for (int i = 1; i < n - 1; i++)
            {
                if (c == 0)
                    break;
                if (s[i] == 1 && s[i + 1] == '0')
                    c -= 2;
                s[i] = '0';
            }
        }
        else
        {
            c = cnt - c;
            if ((c + 2) % 2 == 1)
            {
                s[0] = '0';
                if (s[1] == '1')
                {
                    c++;
                }
                else
                {
                    c--;
                }
            }
            for (int i = 1; i < n - 1; i++)
            {
                if (c == 0)
                    break;
                if (s[i - 1] == '1' && s[i] == '1' && s[i + 1] == '1')
                {
                    s[i] = '0';
                    c += 2;
                }
            }
        }
        cout << s << endl;
        return 0;
    }
