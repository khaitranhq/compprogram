#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <vector>

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
typedef pair<int, int> pii;

const int MAX = 2e5 + 5;
int n;

struct FenwickTree {
  int Tree[MAX];
  int n;

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

  FenwickTree(int n) { this->n = n; }
};

vector<int> findLongestIncreasingSubsequence(vector<int> arr) {
  int largest_element = *max_element(arr.begin(), arr.end());

  FenwickTree BIT(largest_element);

  vector<int> ans;
  return ans;
}

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  cin >> n;
  vector<pii> a;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a.push_back({x, i});
  }

  sort(a.begin(), a.end());

  vector<int> index_of_increase_values;
  index_of_increase_values.push_back(a[0].second);
  for (int i = 1; i < a.size(); ++i) {
    if (abs(a[i].first - a[i - 1].first) > 1) {
      findLongestIncreasingSubsequence(index_of_increase_values);
      index_of_increase_values.clear();
    }

    index_of_increase_values.push_back(a[i].second);
  }
  findLongestIncreasingSubsequence(index_of_increase_values);
  return 0;
}
