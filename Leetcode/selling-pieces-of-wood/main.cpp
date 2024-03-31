#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long sellingWood(int m, int n, vector<vector<int>> &prices) {
    memset(dp, -1, sizeof(dp));
    memset(pricesArray, -1, sizeof(pricesArray));

    for (auto price : prices)
      pricesArray[price[0]][price[1]] =
          max(price[2], pricesArray[price[0]][price[1]]);

    return calculate(m, n);
  }

  long long calculate(int i, int j) {
		if (i == 1 && j == 1) return max(0, pricesArray[i][j]);
    if (dp[i][j] != -1)
      return dp[i][j];

    long long maxPrice = pricesArray[i][j];

    for (int k = 1; k < i; ++k)
      maxPrice = max(maxPrice, calculate(k, j) + calculate(i - k, j));

    for (int k = 1; k < j; ++k)
      maxPrice = max(maxPrice, calculate(i, k) + calculate(i, j - k));

    dp[i][j] = maxPrice;

    return maxPrice;
  }

private:
  static const int MAX_ELEMENTS = 205;
  int dp[MAX_ELEMENTS][MAX_ELEMENTS];
  int pricesArray[MAX_ELEMENTS][MAX_ELEMENTS];
};

int main() {
  int m, n;
  cin >> m >> n;

  int numberPrices;
  vector<vector<int>> prices;
  cin >> numberPrices;
  for (int index = 0; index < numberPrices; ++index) {
    int i, j, price;
    cin >> i >> j >> price;
    prices.push_back({i, j, price});
  }

  Solution solution;
  cout << solution.sellingWood(m, n, prices);
  return 0;
}
