#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string getPermutation(int n, int k) {
    vector<int> currentPermutation;
    for (int i = 1; i <= n; ++i)
      currentPermutation.push_back(i);
    while (--k)
      next_permutation(currentPermutation.begin(), currentPermutation.end());

    string ans = "";
    for (auto i : currentPermutation)
      ans.push_back(i + '0');
    return ans;
  }
};

void expect(string testCase, int n, int k, string expected) {
  Solution sol;
  string result = sol.getPermutation(n, k);
  if (result == expected) {
    cout << "\033[1m"
         << "\033[32m"
         << "PASS: " << testCase << "\033[0m"
         << "\033[0m" << endl;
  } else {
    cout << "\033[1m"
         << "\033[31m"
         << "FAIL: " << testCase << "\033[0m"
         << "\033[0m" << endl;
    cout << "-----------------------------" << endl;
    cout << "Result: " << result << endl;
    cout << "-----------------------------" << endl;
    cout << "Expected: " << expected << endl;
    cout << "-----------------------------" << endl;
    exit(1);
  }
}

int main() {
  expect("Test 1", 3, 3, "213");
  expect("Test 2", 4, 9, "2314");
  expect("Test 3", 3, 1, "123");
  return 0;
}
