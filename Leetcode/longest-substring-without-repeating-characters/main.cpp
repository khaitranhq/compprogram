#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int result = 0;

    int leftPointer = 0, rightPoiner = 0;
    map<char, int> characterNumber;
    characterNumber[s[0]] = 1;
    while (rightPoiner < s.size()) {
      if (characterNumber[s[rightPoiner]] > 1) {
        --characterNumber[s[leftPointer]];
        ++leftPointer;
      } else {
        result = max(result, rightPoiner - leftPointer + 1);
        ++rightPoiner;
        if (rightPoiner < s.size())
          characterNumber[s[rightPoiner]]++;
      }
    }
    return result;
  }
};

int main() {
  string s;
  getline(cin, s);

  Solution solution;
  cout << solution.lengthOfLongestSubstring(s);
  return 0;
}
