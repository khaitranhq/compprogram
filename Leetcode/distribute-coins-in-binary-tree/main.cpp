#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 105;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
} root;

int n;
int coinNumbers[MAX_N];

struct DfsResult {
  int numNodes, sumCoins;
  int resultOfChildTrees;

  DfsResult(int numNodes, int sumCoins, int resultOfChildTrees)
      : numNodes(numNodes), sumCoins(sumCoins),
        resultOfChildTrees(resultOfChildTrees) {}
};

class Solution {
public:
  DfsResult dfs(TreeNode *root) {
    DfsResult leftTreeResult =
        (root->left == nullptr) ? DfsResult(0, 0, 0) : dfs(root->left);
    DfsResult rightTreeResult =
        (root->right == nullptr) ? DfsResult(0, 0, 0) : dfs(root->right);

    DfsResult result = DfsResult(
        leftTreeResult.numNodes + rightTreeResult.numNodes + 1,
        leftTreeResult.sumCoins + rightTreeResult.sumCoins + root->val,
        abs(leftTreeResult.sumCoins - leftTreeResult.numNodes) +
            abs(rightTreeResult.sumCoins - rightTreeResult.numNodes) +
            leftTreeResult.resultOfChildTrees +
            rightTreeResult.resultOfChildTrees);

    return result;
  }

  int distributeCoins(TreeNode *root) { return dfs(root).resultOfChildTrees; }
};

void read() {
  root = TreeNode();
  cin >> n;
  vector<int> coinNumbers(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> coinNumbers[i];
  }

  queue<pair<TreeNode *, int>> q;
  q.push({&root, 1});
  while (q.size()) {
    TreeNode *currentNode = q.front().first;
    int index = q.front().second;
    q.pop();

    currentNode->val = coinNumbers[index - 1];
    if (2 * index <= n) {
      TreeNode *leftNode = new TreeNode();
      currentNode->left = leftNode;
      q.push({leftNode, 2 * index});
    }

    if (2 * index + 1 <= n) {
      TreeNode *rightNode = new TreeNode();
      currentNode->right = rightNode;
      q.push({rightNode, 2 * index + 1});
    }
  }
}

int main(int argc, char *argv[]) {
  freopen("test/1.inp", "r", stdin);
  read();

  Solution solution;
  cout << solution.distributeCoins(&root);
  return 0;
}
