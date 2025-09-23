#include "algorithm"
#include "iostream"
#include "vector"

#define faster()                                                               \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define pb push_back
#define fi first
#define se second
#define ulli pair<unsigned long long, int>
#define ll long long
#define ull unsigned long long

using namespace std;

const int MAX = 1e6 + 1;

vector<ll> a;
vector<bool> check(MAX, 1);

int q;

vector<int> sieve() {
  vector<int> res;
  check[0] = check[1] = 0;
  for (int i = 2; i * i <= MAX; i++)
    if (check[i])
      for (int j = i * i; j <= MAX; j += i)
        check[j] = 0;
  FOR(i, 2, MAX) if (check[i]) res.pb(i);
  return res;
}

vector<ulli> trial_division(ull t, vector<int> primes) {
  vector<ulli> res;
  for (auto p : primes) {
    if (p * p > t)
      break;
    if (t % p)
      continue;
    int cnt = 0;
    while (t % p == 0) {
      cnt++;
      t /= p;
    }
    res.emplace_back(p, cnt);
  }
  if (t > 1)
    res.emplace_back(t, 1);
  return res;
}

ull Power(ull a, int b) {
  ull ans = 1;
  while (b > 0) {
    if (b % 2)
      ans *= a;
    a *= a;
    b /= 2;
  }
  return ans;
}

int main() {
  freopen("BOMCHUM.INP", "r", stdin);
  freopen("BOMCHUM.OUT", "w", stdout);
  faster();
  cin >> q;
  FOR(i, 1, q) {
    ll x, ans = 1;
    cin >> x;
    vector<int> Prime = sieve();
    vector<ulli> Trial_division = trial_division(x, Prime);
    for (auto it : Trial_division) {
      ull temp1 = Power(it.fi, it.se + 1) - 1, temp2 = it.fi - 1;
      ans *= temp1 / temp2;
    }
    cout << ans << " ";
  }
  return 0;
}
