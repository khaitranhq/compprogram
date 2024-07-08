#include <cassert>
#include <queue>
using namespace std;

class Solution {
public:
  int findTheWinner(int n, int k) {
    queue<int> q;

    for (int i = 1; i <= n; ++i)
      q.push(i);

    int currentK = k;
    while (q.size() > 1) {
      --currentK;

      int currentValue = q.front();
      q.pop();
      if (!currentK) {
        currentK = k;
      } else
        q.push(currentValue);
    }

    return q.front();
  }
};

int main() {
  Solution solution;

  assert(solution.findTheWinner(5, 2) == 3);
  assert(solution.findTheWinner(6, 5) == 1);
  assert(solution.findTheWinner(1, 1) == 1);

  return 0;
}
