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

struct Query {
  int l, r, k;
  int index, ans;

  Query() {}
  Query(int l, int r, int k, int index) : l(l), r(r), k(k), index(index) {}
};

const int MAX = 2e5 + 5;
int n, q;
int a[MAX];
vector<Query> queries;

struct FenwickTree {
  int Tree[MAX];

  void update(int u, int x) {
    for (; u <= n; u += u & -u)
      Tree[u] += x;
  }

  int get(int u) {
    int ans = 0;
    for (; u; u -= u & -u)
      ans += Tree[u];
    return ans;
  }

  int get(int u, int v) { return get(v) - get(u - 1); }
} BIT;

bool cmp1(Query x, Query y) { return x.k > y.k; }

bool cmp2(Query x, Query y) { return x.index < y.index; }

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  cin >> n;

  vector<ii> pairs;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pairs.push_back({a[i], i});
  }
  sort(pairs.begin(), pairs.end());

  cin >> q;
  for (int i = 0; i < q; ++i) {
    int l, r, k;
    cin >> l >> r >> k;

    queries.push_back(Query(l, r, k, i));
  }
  sort(queries.begin(), queries.end(), cmp1);

  for (int i = 0; i < q; ++i) {
    while (pairs.size() && pairs.back().first > queries[i].k) {
      BIT.update(pairs.back().second,
                 1); // Mark that position is greater than k
      pairs.pop_back();
    }

    queries[i].ans = BIT.get(queries[i].l, queries[i].r);
  }

  sort(queries.begin(), queries.end(), cmp2);
  for (auto query : queries)
    cout << query.ans << endl;

  return 0;
}
