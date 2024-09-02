#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#define debug(x) cout << #x << " = " << x << endl
#define debugvi(x)                                                             \
  {                                                                            \
    cout << #x << ": ";                                                        \
    for (auto y : x)                                                           \
      cout << y << " ";                                                        \
    cout << endl;                                                              \
  }
using namespace std;

class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words) {
    // save words into hashmap
    map<string, int> wordsCount;
    int wordLength = words[0].size();

    for (int i = 0; i < words.size(); ++i)
      ++wordsCount[words[i]];

    vector<int> result;
    for (int i = 0; i < wordLength; ++i) {
      map<string, int> slidingWindowWordsCount;
      set<string> notEqualWordsNumber;

      // Process the first range
      // from i to i + words.size() * single word length
      // j: count index
      // currentIndex: start index of the current word in s
      for (int j = 0, currentIndex = i;
           j < words.size() - 1 && currentIndex < s.size();
           ++j, currentIndex += wordLength) {
        string currentWord = s.substr(currentIndex, wordLength);
        if (wordsCount.count(currentWord))
          ++slidingWindowWordsCount[currentWord];
      }

      // check which words are not equal to word count that it should be
      for (int j = 0; j < words.size(); ++j) {
        if (slidingWindowWordsCount[words[j]] != wordsCount[words[j]])
          notEqualWordsNumber.insert(words[j]);
      }
      // j: start index of the segment (including words.size() words in s)
      for (int j = i; j < s.size(); j += wordLength) {
        int lastConsiderIndex = j + (words.size() - 1) * wordLength;
        if (lastConsiderIndex < s.size()) {
          string subStr = s.substr(lastConsiderIndex, wordLength);
          if (wordsCount.count(subStr)) {
            ++slidingWindowWordsCount[subStr];
            if (slidingWindowWordsCount[subStr] == wordsCount[subStr])
              notEqualWordsNumber.erase(subStr);
            else
              notEqualWordsNumber.insert(subStr);
          }
        }

        if (!notEqualWordsNumber.size())
          result.push_back(j);

        string subStr = s.substr(j, wordLength);
        if (wordsCount.count(subStr)) {
          --slidingWindowWordsCount[subStr];

          if (slidingWindowWordsCount[subStr] == wordsCount[subStr])
            notEqualWordsNumber.erase(subStr);
          else
            notEqualWordsNumber.insert(subStr);
        }
      }
    }

    return result;
  }
};

void expect(string test, string s, vector<string> words, vector<int> expected) {
  Solution sol;
  vector<int> result = sol.findSubstring(s, words);
  sort(result.begin(), result.end());
  if (result == expected) {
    cout << "\033[1m" << "\033[32m" << "PASS: " << test << "\033[0m"
         << "\033[0m" << endl;
  } else {
    cout << "\033[1m" << "\033[31m" << "FAIL: " << test << "\033[0m"
         << "\033[0m" << endl;
    cout << "s" << ": " << s << endl;
    debugvi(words);
    cout << "result: ";
    for (auto x : result)
      cout << x << " ";
    cout << endl;
    cout << "expected: ";
    for (auto x : expected)
      cout << x << " ";
    cout << endl;
    cout << "-----------------------------" << endl;
    exit(1);
  }
}
int main() {
  expect("test 1", "barfoothefoobarman", {"foo", "bar"}, {0, 9});
  expect("test 2", "wordgoodgoodgoodbestword", {"word", "good", "best",
  "word"},
         {});
  expect("test 3", "barfoofoobarthefoobarman", {"foo", "bar", "the"},
         {6, 9, 12});
  expect("test 4", "word", {"word"}, {0});
  expect("test 5", "aaaaaaaaaaaaaaa", {"aa", "aa", "aa"},
         {0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  return 0;
}
