#include <bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd
#define ll long long
const ll MAXN = 5, MAXA = 26;
ll n, m;

long long Rand(long long l, long long h) {
  assert(l <= h);
  return l + rd() * 1LL * rd() % (h - l + 1);
}

int main() {
  srand(time(NULL));
  for (int iTest = 1; iTest <= 1000; iTest++) {
    ofstream inp("data.inp");
    int n = Rand(1, MAXN), m = Rand(1, MAXN);
    inp << n << " " << m << "\n";
    for (ll i = 1; i <= n; ++i)
      for (ll j = 1; j <= m; ++j) {
        int x = Rand(-1, MAXA);

      }
    inp.close();

    system("./data");
    system("./data_t");
    if (system("cmp data.out data.ans") != 0) {
      cout << "Test " << iTest << ": WRONG!\n";
      return 0;
    }
    cout << "Test " << iTest << ": CORRECT!\n";
  }
  return 0;
}
