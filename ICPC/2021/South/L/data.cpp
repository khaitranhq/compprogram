#include <bits/stdc++.h>
#include <cstdio>

#define debug(x) cerr << #x << " = " << x << endl;
#define debugarr(x, n)                                                         \
  {                                                                            \
    for (int _ = 0; _ < n; ++_)                                                \
      cerr << x[_] << " ";                                                     \
    cerr << endl;                                                              \
  }
#define debugarr2d(x, n, m)                                                    \
  {                                                                            \
    for (int __ = 0; __ < n; ++__)                                             \
      debugarr(x[__], m);                                                      \
    cerr << endl;                                                              \
  }
#define debugvi(x)                                                             \
  {                                                                            \
    for (int _ = 0; _ < x.size(); ++_)                                         \
      cerr << x[_] << " ";                                                     \
    cerr << endl;                                                              \
  }

using namespace std;

typedef int64_t ll;
const int MAX = 1e5 + 5;
int n, m;
int a[MAX];
bool q[MAX];
int nearOne[MAX], nearZero[MAX];
ll f[MAX];

void enter() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  string s;
  cin >> s;
  m = s.size();
  for (int i = 0; i < m; ++i)
    q[i + 1] = s[i] - '0';
}

void init() {
  nearOne[m + 1] = m + 1, nearZero[m + 1] = m + 1;
  for (int i = m; i >= 1; --i)
    if (q[i]) {
      nearOne[i] = i;
      nearZero[i] = nearZero[i + 1];
    } else {
      nearOne[i] = nearOne[i + 1];
      nearZero[i] = i;
    }
}

void solve() {
  enter();
  init();

  auto update = [](int l, int r, int x) {
    f[l] += x;
    f[r + 1] -= x;
  };

  for (int i = 1; i <= n; ++i) {
    int j = 1;
    while (j <= m && a[i]) {
      if (a[i] % 2) { // odd
        if (!q[j]) {
          update(j, nearOne[j] - 1, a[i]);
          j = nearOne[j];
        } else {
          --a[i];
          update(j, j, a[i]);
          ++j;
        }
      } else { // even
        if (q[j]) {
          update(j, nearZero[j] - 1, a[i]);
          j = nearZero[j];
        } else {
          a[i] /= 2;
          update(j, j, a[i]);
          ++j;
        }
      }
    }
  }

  for (int i = 1; i <= m; ++i) {
    f[i] = f[i - 1] + f[i];
    cout << f[i] << endl;
  }
}

int main() {
  int numberTestCase = 1;
#ifdef LOCAL
  numberTestCase = 1;
#endif

  for (int test = 1; test <= numberTestCase; ++test) {
#ifdef LOCAL
    string inputFileName = "test/" + to_string(test) + ".inp";
    freopen(inputFileName.c_str(), "r", stdin);

    string outputFileName = "test/" + to_string(test) + ".out";
    freopen(outputFileName.c_str(), "w", stdout);
#endif

    // Main function here
    solve();
    // End main function

#ifdef LOCAL
    string answerFileName = "test/" + to_string(test) + ".ans";
    string diffCommand = "diff " + outputFileName + " " + answerFileName;
    if (system(diffCommand.c_str()) != 0) {
      cerr << "Test #" << test << ": WRONG!\n";
      return 0;
    }
    cerr << "Test #" << test << ": CORRECT!\n";

    fclose(stdin);
    fclose(stdout);
#endif
  }
  return 0;
}
