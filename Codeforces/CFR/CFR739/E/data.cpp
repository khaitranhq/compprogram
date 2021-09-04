#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)                                                    \
  {                                                                            \
    for (int _ = 0; _ < n; ++_) {                                              \
      for (int __ = 0; __ < m; ++__)                                           \
        cout << x[_][__] << " ";                                               \
      cout << endl;                                                            \
    }                                                                          \
    cout << endl;                                                              \
  }
#define debugarr(x, n)                                                         \
  {                                                                            \
    for (int _ = 0; _ < n; ++_)                                                \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }
#define debugvi(x)                                                             \
  {                                                                            \
    for (int _ = 0; _ < x.size(); ++_)                                         \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }

using namespace std;

typedef vector<char> vc;
typedef pair<char, int> pci;

const int MAX_CHARACTERS = 26;
int numberCharacters[MAX_CHARACTERS];

/*
 * Find deleted order of string s
 *
 * @param t: input string
 *
 * @return: deleted order list contains characters
 */
vc findOrder(string t) {
  vc ans;

  pci last_index[MAX_CHARACTERS]; // last index of each character in t

  memset(last_index, -1, sizeof(last_index));
  for (int i = 0; i < t.size(); ++i)
    last_index[t[i] - 'a'] = {t[i], i};

  sort(last_index, last_index + MAX_CHARACTERS,
       [](pci x, pci y) { return x.second > y.second; });

  for (int i = 0; i < MAX_CHARACTERS; ++i)
    if (last_index[i].second != -1)
      ans.push_back(last_index[i].first);

  reverse(ans.begin(), ans.end());

  return ans;
}

/*
 * Check whether number character each letter not divisible by order
 *
 * @param t: input string
 * @param deletedOrder: deleted order of lettes
 *
 * return: valid/not
 */
bool checkValidNumberCharacter(string t, vc deletedOrder) {
  //   // if a letter was deleted at time x-th, total number characters of it is x *
  // ...
  memset(numberCharacters, 0, sizeof(numberCharacters));
  for (int i = 0; i < t.size(); ++i)
    numberCharacters[t[i] - 'a']++;

  for (int i = 0; i < deletedOrder.size(); ++i)
    if (numberCharacters[deletedOrder[i] - 'a'] % (i + 1) != 0)
      return false;
  return true;
}

/*
 * Build new t from s
 *
 * @param s: input string
 * @param deletedOrder: deleted order of letters
 *
 * return: new string t built from s
 */
string generateTString(string s, vc deletedOrder) {
  string currentString = s, ans = "";
  int orderCount = 0;

  while (currentString.size()) {
    ans.append(currentString);

    string tmp = "";
    for (int i = 0; i < currentString.size(); ++i)
      if (currentString[i] != deletedOrder[orderCount])
        tmp.push_back(currentString[i]);

    ++orderCount;
    currentString = tmp;
  }

  return ans;
}

/*
 * Get initial string
 *
 * @param t : input string
 * @param deletedOrder: deleted order of letters
 *
 * @return initial string
 */
string getInitialString(string t, vc deletedOrder) {
  if (checkValidNumberCharacter(t, deletedOrder))
    return "";

  // Get inital string
  int formattedDeletedOrder[MAX_CHARACTERS]; // fill in all letters, any letter
                                             // not exist in t will have value 0
  memset(formattedDeletedOrder, 0, sizeof(formattedDeletedOrder));

  for (int i = 0; i < deletedOrder.size(); ++i)
    formattedDeletedOrder[deletedOrder[i] - 'a'] = i + 1;

  int countNumberCharacters[MAX_CHARACTERS];
  int lastIndexOfString = -1;

  memset(countNumberCharacters, 0, sizeof(countNumberCharacters));

  for (int i = 0; i < t.size(); ++i) {
    int j = t[i] - 'a';
    ++countNumberCharacters[j];
    if (countNumberCharacters[j] ==
        numberCharacters[j] / formattedDeletedOrder[j])
      lastIndexOfString = max(lastIndexOfString, i);
  }

  string ans = t.substr(0, lastIndexOfString + 1);

  // Check string t with string ans
  string newString = generateTString(ans, deletedOrder); // String generate from ans
  if (t.compare(newString) != 0)
    return "";

  return ans;
}

void solve(string t) {
  vc deletedOrder = findOrder(t);

  string initialString = getInitialString(t, deletedOrder);

  if (initialString == "") {
    cout << -1 << endl;
    return;
  }

  cout << initialString << " ";

  for (int i = 0; i < deletedOrder.size(); ++i)
    cout << deletedOrder[i];
  cout << endl;
}

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
    string t;
    cin >> t;
    solve(t);
  }
  return 0;
}
