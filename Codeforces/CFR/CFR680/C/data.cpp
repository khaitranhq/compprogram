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

template <typename T> void Read(T &x){
	char ch;
	x = 0;
	while(!isdigit(ch = getchar()));
	do{x = x * 10 + ch - 48;} while(isdigit(ch = getchar()));
	return;}
template <typename T> void Write(T x){
	char ch[32];
	int cnt = 0;
	do{ch[++cnt] = x % 10 + 48 ; x /= 10;} while(x);
  for (int i = cnt; i >= 1; --i)
	putchar(ch[i]);}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--) {
      ll p, q;
      Read(p); Read(q);

      if (p % q) {
        cout << p << endl;
        continue;
      }

      ll ans = p;
      while(ans % q == 0) ans /= q;

      for (ll i = 2; i * i <= q; ++i)
        if (q % i == 0){
          ll tmp = p;
          if (tmp % q == 0) {
            while (tmp % q == 0 && tmp % i == 0) tmp /= i;
            ans = max(ans, tmp);
          }

          tmp = p;
          if (tmp % (q / i) == 0) {
            while (tmp % q == 0 && tmp % (q / i) == 0) tmp /= (q / i);
            ans = max(ans, tmp);
          }
        }

      cout << ans << endl;
    }
    return 0;
}
