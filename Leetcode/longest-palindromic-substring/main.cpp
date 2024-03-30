#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int ansLeftPos = 0, ansRightPos = 0;
    for (int i = 0; i < s.size(); ++i) {

      // Case 1: Palindrome has odd-length
      for (int j = 0; (i + j + 1 < s.size()) && (i - j >= 0); ++j) {
        int r = i + j + 1, l = i - j;
        if (s[l] != s[r])
          break;

        if (r - l > ansRightPos - ansLeftPos)
          ansLeftPos = l, ansRightPos = r;
      }

      // Case 2: Palindrome has even-length
      for (int j = 1; (i + j < s.size()) && (i - j >= 0); ++j) {
        int r = i + j, l = i - j;
        if (s[l] != s[r])
          break;

        if (r - l > ansRightPos - ansLeftPos)
          ansLeftPos = l, ansRightPos = r;
      }
    }

    return s.substr(ansLeftPos, ansRightPos - ansLeftPos + 1);
  }
};

int main() {
  Solution solution;

  string s;
  cin >> s;

  cout << solution.longestPalindrome(s);
  return 0;
}
