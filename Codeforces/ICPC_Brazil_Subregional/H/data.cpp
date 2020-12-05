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
        for (int _ = 1; _ <= n; ++_) \
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

const int MAX = 55;
ll c[MAX][MAX];
int n, k;
ll a, b;
ll w[MAX];

void calcCombination() {
  for (int i = 0; i <= 50; ++i)
    c[i][0] = 1;

  for (int i = 1; i <= 50; ++i)
    for (int j = 1; j <= 50; ++j) 
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
}

ll compute(ll x) {
  int remainK = k;
  ll ans = 0;
  for (int i = 1; i <= n; ++i)
    if (w[i] < x && remainK) {
      debug(i);
      debug(remainK)
      debug(x)
      debug(c[n - i][remainK])
      debug(w[i])
      debug(x - w[i])
      cout << endl;

      ans += c[n - i][remainK]; 
      --remainK;
      x -= w[i];
    } else
      if (w[i] == x && remainK == 1) {
        ans += n - i + 1;
        x = 0;
      }
  return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    memset(c, 0, sizeof(c));
    calcCombination();

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
      cin >> w[i];
    cin >> a >> b;

    sort(w + 1, w + n + 1, greater<int>());

    debugarr(w, n)

    ll ansB = compute(b);
    // ll ansA = compute(a - 1);

    debug(ansB);
    // debug(ansA)

    // cout << ansB - ansA;
    return 0;
}
