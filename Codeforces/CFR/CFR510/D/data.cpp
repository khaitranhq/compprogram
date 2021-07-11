#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)                                                    \
  {                                                                            \
    for (int _ = 0; _ < n; ++_) {                                              \
      for (int __ = 0; __ < m; ++__)                                           \
        cout << x[_][__] << " ";                                               \
      cout << endl;                                                            \
    }                                                                          \
    cout << endl;                                                              \
  }
#define debugarr(x, n)                                                         \
  {                                                                            \
    for (int _ = 0; _ < n; ++_)                                                \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }
#define debugvi(x)                                                             \
  {                                                                            \
    for (int _ = 0; _ < x.size(); ++_)                                         \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }

#define fi first
#define se second
#define pb push_back
using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

struct Query {
  ll index, k;

  Query() {}
  Query(ll index, ll k) : index(index), k(k) {}

  bool operator<(const Query &other) { return this->k > other.k; }
};

const int MAX = 2e5 + 5;
int n;
ll t;
ll a[MAX], prefixSum[MAX];

struct FenwickTree {
  ll Tree[MAX];

  void update(int u, int x) {
    for (; u <= n; u += u & -u)
      Tree[u] += x;
  }

  ll get(int u) {
    ll ans = 0;
    for (; u; u -= u & -u)
      ans += Tree[u];
    return ans;
  }
} BIT;

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  cin >> n >> t;

  ll res = 0;
  vector<pll> indexValue;
  vector<Query> queries;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];

    prefixSum[i] = prefixSum[i - 1] + a[i];
    if (prefixSum[i] - t < 0)
      ++res;

    indexValue.push_back({prefixSum[i], i});
    queries.push_back(Query(i, prefixSum[i] - t));
  }

  sort(indexValue.begin(), indexValue.end());
  sort(queries.begin(), queries.end());

  for (auto query : queries) {
    while (indexValue.size() && indexValue.back().first > query.k) {
      BIT.update(indexValue.back().second, 1);
      indexValue.pop_back();
    }

    res += BIT.get(query.index - 1);
  }
  cout << res;

  return 0;
}
