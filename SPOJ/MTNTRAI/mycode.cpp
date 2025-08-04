#include "iostream"
#include "queue"

#define faster()                                                               \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;

const int MAX = 1e3 + 1;

// Grid dimensions and movement directions
int gridWidth, gridHeight, directionX[] = {0, 0, 1, -1},
                           directionY[] = {1, -1, 0, 0};
// Global counters for total counts across all components
int totalCows = 0, totalFarms = 0;
// Local counters for current component being processed
int currentCows = 0, currentFarms = 0;
char grid[MAX][MAX];
bool visited[MAX][MAX];

/**
 * Performs BFS to explore a connected component and count cows ('c') and farms
 * ('f')
 * @param startX Starting x-coordinate (row)
 * @param startY Starting y-coordinate (column)
 */
void exploreConnectedComponent(int startX, int startY) {
  queue<ii> explorationQueue;
  explorationQueue.push({startX, startY});
  visited[startX][startY] = true;

  // Count the starting cell if it contains a cow or farm
  if (grid[startX][startY] == 'c')
    currentFarms++;
  if (grid[startX][startY] == 'f')
    currentCows++;

  while (!explorationQueue.empty()) {
    int currentX = explorationQueue.front().fi;
    int currentY = explorationQueue.front().se;
    explorationQueue.pop();

    // Explore all 4 directions (up, down, left, right)
    FOR(direction, 0, 3) {
      int nextX = currentX + directionX[direction];
      int nextY = currentY + directionY[direction];

      // Check bounds
      if (nextX > gridHeight || nextX < 1)
        continue;
      if (nextY > gridWidth || nextY < 1)
        continue;

      // If cell is not a wall and not visited, explore it
      if (grid[nextX][nextY] != '#' && !visited[nextX][nextY]) {
        if (grid[nextX][nextY] == 'c')
          currentFarms++;
        if (grid[nextX][nextY] == 'f')
          currentCows++;
        visited[nextX][nextY] = true;
        explorationQueue.push({nextX, nextY});
      }
    }
  }
}

int main() {
  // For SPOJ, we might need file I/O for local testing
  // Remove these lines for online submission if not needed
#ifdef LOCAL
  freopen("main.inp", "r", stdin);
  freopen("main.out", "w", stdout);
#endif

  cin >> gridHeight >> gridWidth;

  // Read the grid
  FOR(row, 1, gridHeight) {
    FOR(col, 1, gridWidth) { cin >> grid[row][col]; }
  }

  // Process each cell to find connected components
  FOR(row, 1, gridHeight) {
    FOR(col, 1, gridWidth) {
      currentCows = 0;
      currentFarms = 0;

      // If cell is not a wall and not visited, start BFS from this cell
      if (grid[row][col] != '#' && !visited[row][col]) {
        exploreConnectedComponent(row, col);

        // Add the dominant count from this component to the total
        if (currentFarms > currentCows)
          totalFarms += currentFarms;
        else
          totalCows += currentCows;
      }
    }
  }

  cout << totalCows << " " << totalFarms;
  return 0;
}
