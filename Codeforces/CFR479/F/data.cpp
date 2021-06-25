#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <vector>
#include <functional>

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

int n;
vector<pii> a;

void enter() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a.push_back({x, i});
  }
}

void findLongestConsecutiveIncreasingSubsequence(
    vector<int> arr, vector<int> &maximumSubsequence) {
  vector<int> cur;

  function<void(void)> maximizeAnswer = [&] {
    if (maximumSubsequence.size() < cur.size())
      maximumSubsequence = cur;
  };

  for (size_t i = 0; i < arr.size(); ++i) {
    if (!cur.size() || arr[i] > cur.back())
      cur.push_back(arr[i]);
    else {
      maximizeAnswer();
      cur.clear();
      cur.push_back(arr[i]);
    }
  }
  maximizeAnswer();
}

void solve() {
  function<bool(pii, pii)> cmp = [=](pii x, pii y) {
    if (x.first != y.first) return x.first < y.first;
    return x.second > y.second;
  };

  sort(a.begin(), a.end(), cmp);

  //   for (size_t i = 0; i < a.size(); ++i)
  //   cout << a[i].first << " " << a[i].second << endl;
  // cout << endl;

  vector<int> index_of_increase_values, res;
  index_of_increase_values.push_back(a[0].second);
  for (size_t i = 1; i < a.size(); ++i) {

    if (a[i].first - a[i - 1].first != 1) {
      findLongestConsecutiveIncreasingSubsequence(index_of_increase_values,
                                                  res);
      index_of_increase_values.clear();
    }

    index_of_increase_values.push_back(a[i].second);
  }
  findLongestConsecutiveIncreasingSubsequence(index_of_increase_values, res);

  cout << res.size() << endl;
  for (size_t i = 0; i < res.size(); ++i)
    cout << res[i] << " ";
}

int main() {
// #ifdef LOCAL
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
// #endif
  
  enter();
  solve();
  return 0;
}
