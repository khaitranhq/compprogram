#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
  int checkRecord(int n) {
    memset(f, -1, sizeof(f));

    int ans = 0;
    for (int j = 0; j < 3; ++j)
      for (int a = 0; a < 2; ++a)
        for (int l = 0; l < 3; ++l) {
          ans = (ans + dp(n, j, a, l)) % MOD_BASE;
        }

    return ans;
  }

private:
  const int MAXN = 1e5 + 5;
  const int MOD_BASE = 1e9 + 7;
  // Number of possible attendance records
  // [i][j][a][l]
  // i: length of attendance records
  // j: character at i (0 -> A, 1 -> L, 2 -> P)
  // a: number of characters A (< 2)
  // l: number of consecutive characters L (< 3)
  int f[MAXN][3][2][3];

  int dp(int currentLength, int currentChar, int numberAs,
         int numberConsecutiveLs) {
    // Wrong cases
    if (currentChar == 0 && numberAs == 0)
      return 0;
    if ((currentChar == 0 || currentChar == 2) && numberConsecutiveLs > 0)
      return 0;
    if (currentChar == 1 && numberConsecutiveLs == 0)
      return 0;
    if (numberConsecutiveLs > currentLength - numberAs)
      return 0;

    if (currentLength == 1) {
      if (currentChar == 2 && numberAs == 1)
        return 0;

      f[currentLength][currentChar][numberAs][numberConsecutiveLs] = 1;
      return 1;
    }

    if (f[currentLength][currentChar][numberAs][numberConsecutiveLs] != -1)
      return f[currentLength][currentChar][numberAs][numberConsecutiveLs];

    int ans = 0;
    switch (currentChar) {
    // A
    case 0:
      for (int j = 1; j < 3; ++j)
        for (int l = 0; l < 3; ++l)
          ans = (ans + dp(currentLength - 1, j, 0, l)) % MOD_BASE;
      break;
    // L
    case 1:
      if (numberConsecutiveLs == 2)
        ans = (ans + dp(currentLength - 1, 1, numberAs, 1)) % MOD_BASE;

      if (numberConsecutiveLs == 1) {
        ans = (ans + dp(currentLength - 1, 2, numberAs, 0)) % MOD_BASE;
        if (numberAs == 1)
          ans = (ans + dp(currentLength - 1, 0, numberAs, 0)) % MOD_BASE;
      }
      break;
    // P
    case 2:
      if (numberAs == 1)
        ans = (ans + dp(currentLength - 1, 0, numberAs, 0)) % MOD_BASE;

      for (int l = 0; l < 3; ++l)
        ans = (ans + dp(currentLength - 1, 1, numberAs, l)) % MOD_BASE;

      ans = (ans + dp(currentLength - 1, 2, numberAs, 0)) % MOD_BASE;
      break;
    }

    f[currentLength][currentChar][numberAs][numberConsecutiveLs] = ans;
    // cout << currentLength << " " << currentChar << " " << numberAs << " "
    //      << numberConsecutiveLs << endl;
    // cout << ans << endl << endl;
    return ans;
  }
};

int main(int argc, char *argv[]) {
  freopen("test/0.inp", "r", stdin);
  int n;
  cin >> n;

  Solution solution;
  cout << solution.checkRecord(n);
  return 0;
}
