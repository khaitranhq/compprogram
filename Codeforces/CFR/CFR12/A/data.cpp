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

int num[26];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--) {:w
      string s;
      cin >> s;
      for (int i = 0; i < s.size(); ++i)
        ++num[s[i] - 'a'];

      string test = "bugyrt";
      for (int i = 0; i < test.size(); ++i)
        for (int j = 0; j < num[test[i] - 'a']; ++j) cout << test[i];

      for (char i = 'a'; i <= 'z'; ++i) {
        bool flag = 1;
        for (int j = 0; j < test.size(); ++j)  
          if (i == )
        
    }
    return 0;
}
