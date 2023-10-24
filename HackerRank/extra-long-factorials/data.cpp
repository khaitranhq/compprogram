#include <bits/stdc++.h>

using namespace std;

typedef vector<int> BigInt; // Reversed digits

string ltrim(const string &);
string rtrim(const string &);

BigInt initialize(int x) {
  BigInt ans;
  do {
    ans.push_back(x % 10);
    x /= 10;
  } while (x);
  return ans;
}

BigInt multipleBigInts(BigInt a, BigInt b) {
  BigInt ans;
  ans.assign(a.size() + b.size(), 0);

  if (a.size() < b.size())
    swap(a, b);

  for (int i = 0; i < a.size(); ++i) {
    int carry = 0;
    for (int j = 0; j < b.size() || carry > 0; ++j) {
      int sum = ans[i + j] + carry + a[i] * (j < b.size() ? b[j] : 0);
      ans[i + j] = sum % 10;
      carry = sum / 10;
    }
  }

  while (ans.back() == 0)
    ans.pop_back();

  return ans;
}

void printBigInt(BigInt x) {
  reverse(x.begin(), x.end());
  for (int i = 0; i < x.size(); ++i)
    cout << x[i];
}

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void extraLongFactorials(int n) {
  BigInt ans = initialize(1);
  // printBigInt(ans);
  for (int i = 1; i <= n; ++i) {
    BigInt bignIntI = initialize(i);
    ans = multipleBigInts(ans, bignIntI);
  }

  printBigInt(ans);
}

int main() {
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  extraLongFactorials(n);

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}
