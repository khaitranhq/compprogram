#include <bits/stdc++.h>

using namespace std;
int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
#endif
  int n;
  cin >> n;
  int arr[100009];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int assas;
  cin >> assas;
  int hole;
  cin >> hole;
  for (int i = 0; i < n; i++) {
    arr[i] = abs(arr[i] - hole);
  }
  sort(arr, arr + n);
  assas = abs(assas - hole);
  long long sum = 0;
  int res = 0;
  arr[n] = 0;
  for (int i = 0; i <= n; i++) {
    sum += arr[i];
    if (sum >= assas) {
      res = i;
      break;
    }
  }
  cout << res << endl;
  return 0;
}
