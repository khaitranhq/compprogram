#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string largestPalindromic(string num) {
    vector<int> digitCount(10, 0);
    for (int i = 0; i < num.size(); ++i)
      digitCount[num[i] - '0']++;

    int middleDigit = -1;
    string halfResult = "";
    for (int i = 9; i >= 0; --i) {
      if (i != 0 || (i == 0 & halfResult.size() != 0))
        halfResult.append(digitCount[i] / 2, i + '0');
      if (( digitCount[i] % 2 || (halfResult.size() == 0 && i == 0) ) && middleDigit == -1)
        middleDigit = i;
    }

    string result = halfResult;
    if (middleDigit != -1)
      result.append(to_string(middleDigit));
    reverse(halfResult.begin(), halfResult.end());
    result.append(halfResult);

    return result;
  }
};

int main() {
  string inputNum;
  cin >> inputNum;

  Solution solution;

  string result = solution.largestPalindromic(inputNum);
  cout << result;

  return 0;
}
