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
typedef vector<bool> vb;
typedef pair<int, int> pii;

const int MAX = 2e5 + 5;
int n;
int value[MAX];
vb a[MAX];
int lastOneIndex[MAX];

struct FenwickTree {
  int Tree[MAX];
  int n;

  FenwickTree(int n) {
    for (int i = 0; i <= n; ++i) Tree[i] = 0;
    this -> n = n;
  }

  void update(int u, int value) {
    for (; u <= n; u += u & -u)
      Tree[u] += value;
    // debugarr(Tree, n)
  }

  int query(int u) {
    int ans = 0;
    for (; u; u -= u & -u)
      ans += Tree[u];
    return ans;
  }

  void update(int u, int v, int value) {
    update(u, value);
    update(v + 1, -value);
  }
};

vb convertDec2Bin(int x, int len) {
  vb ans;
  do {
    ans.push_back(x % 2);
    x /= 2;
  } while (x);
  while (ans.size() < len)
    ans.push_back(0);

  // for (auto tmp: ans) cout << tmp << " ";

  return ans;
}

void solve() {
  int n;
  cin >> n;

  int maxValueIndex = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> value[i];
    if (!maxValueIndex || value[i] > value[maxValueIndex])
      maxValueIndex = i;
  }

  for (int i = 1; i <= n; ++i) {
    a[i] = convertDec2Bin(value[i], log2(value[maxValueIndex]) + 1);
    lastOneIndex[i] = log2(value[i]) + 1;
  }

  FenwickTree BIT = FenwickTree(n);
  for (int i = maxValueIndex - 1; i; --i) {
    for (int j = 0; j < lastOneIndex[i]; ++j) {
      if (!a[i][j] && a[maxValueIndex][j]) {
        BIT.update(i, i, (1 << j));
      }

      if (a[i][j] && !a[maxValueIndex][j]) {
        BIT.update(i + 1, maxValueIndex, (1 << j));
        a[maxValueIndex][j] = 1;
      }
    }
    debug(i);
    debugarr(BIT.Tree, n);
    cout << endl;
  }

  for (int i = maxValueIndex + 1; i <= n; ++i) {
    for (int j = 0; j < a[i].size(); ++j) {
      if (a[i][j] != a[maxValueIndex][j])
        BIT.update(i, i, (1 << j));
    }
  }

  for (int i = 1; i <= n; ++i)
    cout << BIT.query(i) << " ";

  cout << endl;
}

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
