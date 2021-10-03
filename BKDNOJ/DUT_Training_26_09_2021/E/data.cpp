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

typedef vector<int> vi;

struct node {
  set<node>::iterator parentNode;
  string name;
  set<string> childName;
  map<string, set<node>::iterator> childLink;

  node() {}
  node(set<node>::iterator parentNode) : parentNode(parentNode) {}
};

typedef set<node>::iterator si;
set<node> directories;

bool mkdir(string name, si currentNode) {
  if (currentNode->childName.count(name))
    return 0;

  directories.insert(node(currentNode));
  currentNode -> childName.insert(name);
  return 1;
}

bool rm(string name, si currentNode) {
  if (currentNode->childName.count(name))
    return 0;

  si childNode = currentNode->childLink.at(name);
  directories.erase(childNode);
  return 1;
}

bool cd(string name, si currentNode) {
  if (name == "..") {
    if (currentNode->name == "root")
      return 0;

    currentNode = currentNode->parentNode;
  }

  if (!currentNode->childName.count(name))
    return 0;

  currentNode = currentNode->childLink.at(name);
  return 1;
}

bool sz() {}

void ls(si currentNode) {
  set<string> childName = currentNode->childName;
  if (!childName.size())
    cout << "EMPTY";

  if (childName.size() <= 10) {
    for (map<string, si>::iterator it = childName.begin();
         it != childName.end(); ++it) {
      cout << it -> first << endl;
    }
  }

  if (childName.size() > 10) {
    for (map<string, si>::iterator it = )
  }
}

bool tree() {}
bool undo() {}

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
    int Q;
    cin >> Q;

    while (Q--) {
    }
  }

  return 0;
}
