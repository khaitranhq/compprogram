#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set<string> good;
map<string, int> cnt;

string normalize1(string s) {
  string res = "";
  for (auto c : s) {
    if (!isalpha(c))
      continue;
    c = toupper(c);
    res += c;
  }
  return res.substr(0, 20);
}

string normalize2(string s) {
  string res = "";
  for (auto c : s) {
    if (!isalpha(c) && !isdigit(c))
      continue;
    c = toupper(c);
    res += c;
  }
  return res.substr(0, 10);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string H, T, M;
    cin >> H >> T >> M;
    H = normalize1(H);
    T = normalize1(T);
    M = normalize2(M);
    if (H.length() > 20 || T.length() > 20 || M.length() > 10)
      assert(0);
    string hsh = H + ',' + T + ',' + M;
    if (good.find(hsh) == good.end()) {
      good.insert(hsh);
      cnt[M]++;
    }
  }

  for (auto p : cnt) {
    cout << p.first << ' ' << p.second << ' ';
    if (p.second >= 10)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
