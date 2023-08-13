#include "main.h"

int main() {
  vector<int> ranked = {100, 90, 90, 80};
  vector<int> player = {70, 80, 105};

  vector<int> playerRank = climbingLeaderboard(ranked, player);

  for (int rank : playerRank) {
    cout << rank << " ";
  }
  return 0;
}
