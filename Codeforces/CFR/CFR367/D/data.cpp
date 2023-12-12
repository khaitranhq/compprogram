#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr(x, n)                                                         \
  {                                                                            \
    for (int _ = 0; _ < n; ++_)                                                \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }
#define debugarr2d(x, n, m)                                                    \
  {                                                                            \
    for (int __ = 0; __ < n; ++__)                                             \
      debugarr(x[__], m);                                                      \
    cout << endl;                                                              \
  }
#define debugvi(x)                                                             \
  {                                                                            \
    for (int _ = 0; _ < x.size(); ++_)                                         \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }

using namespace std;

typedef vector<bool> vb;

const int NUMBER_NODES = 1e7;

bool getBit(int x, int index) { return (x >> index) & 1; }

struct Trie {
  struct Node {
    int child[2];
    int numberLastNode; // Number of numbers use this node as the last node
    int count;          // Numbers of number use this node
  } nodes[NUMBER_NODES];

  int totalNumberNodes;
  Trie() : totalNumberNodes(0) {
    nodes[0].child[0] = nodes[0].child[1] = -1;
    nodes[0].numberLastNode = nodes[0].count = 0;
  }

  void add(int x) {
    int nodeIndex = 0;
    for (int i = 30; i >= 0; --i) {
      int bit = getBit(x, i);
      if (nodes[nodeIndex].child[bit] == -1) { // Need create a new node
        totalNumberNodes++;
        nodes[totalNumberNodes].child[0] = nodes[totalNumberNodes].child[1] =
            -1;
        nodes[totalNumberNodes].numberLastNode = nodes[totalNumberNodes].count =
            0;

        nodes[nodeIndex].child[bit] = totalNumberNodes;
      }

      nodeIndex = nodes[nodeIndex].child[bit];
      nodes[nodeIndex].count++;
    }

    nodes[nodeIndex].numberLastNode++;
  }

  void remove(int x) {
    int nodeIndex = 0;
    int previousNodeIndex = 0;
    for (int i = 30; i >= 0; --i) {
      int bit = getBit(x, i);

      previousNodeIndex = nodeIndex;
      nodeIndex = nodes[nodeIndex].child[bit];
      nodes[nodeIndex].count--;

      if (nodes[nodeIndex].count == 0) {
        nodes[previousNodeIndex].child[getBit(x, i)] = -1;
      }
    }
  }

  int findMaxXor(int x) {
    int nodeIndex = 0;
    int maxXor = 0;

    // // DEBUG
    //   for (int i = 0; i <= 40; ++i) {
    //     printf("%d - %d %d\n", i, nodes[i].child[0], nodes[i].child[1]);
    //   }

    for (int i = 30; i >= 0; --i) {
      int bit = getBit(x, i);
      // if (nodes[nodeIndex].child[0] == -1 && nodes[nodeIndex].child[1] == -1)
      //   return x;

      if (nodes[nodeIndex].child[bit ^ 1] != -1) {
        maxXor += (1 << i);
        nodeIndex = nodes[nodeIndex].child[bit ^ 1];
      } else {
        nodeIndex = nodes[nodeIndex].child[bit];
      }

      // // DEBUG
      //    printf("%d %d %d\n", i, bit, maxXor);
    }

    return maxXor;
  }
} trie;

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
#endif

  int q;
  cin >> q;
  trie.add(0);
  while (q--) {
    char type;
    int x;
    do {
      scanf("%c", &type);
    } while (type != '+' && type != '-' && type != '?');

    cin >> x;

    switch (type) {
    case '+':
      trie.add(x);
      break;
    case '-':
      trie.remove(x);
      break;
    case '?':
      cout << trie.findMaxXor(x) << endl;
      break;
    }
  }

  // for (int i = 0; i <= 31; ++i) {
  //   cout << "Child: " << trie.nodes[i].child[0] << " " <<
  //   trie.nodes[i].child[1]
  //        << endl;
  //
  //   cout << "Count: " << trie.nodes[i].count;
  //   cout << endl << endl;
  // }
  return 0;
}
