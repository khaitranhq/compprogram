#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> result;

    int lineNumber = 0;
    for (int i = 0; i < words.size();) {
      ++lineNumber;
      cout << "Line number: " << lineNumber << endl;

      vector<string> currentLineWords;
      int totalWordsLength = 0;
      while (i < words.size() &&
             totalWordsLength + words[i].size() + currentLineWords.size() - 1 <=
                 maxWidth) {
        currentLineWords.push_back(words[i]);
        totalWordsLength += words[i].size();
        ++i;
      }

      int numberOfSpaces = maxWidth - totalWordsLength;
      int numberOfOverSpace =
          numberOfSpaces - (numberOfSpaces / (currentLineWords.size() - 1)) *
                         (currentLineWords.size() - 1);
      int numberOfSpacesPerWord =
          numberOfSpaces / (currentLineWords.size() - 1);
      string currentLine = "";

      cout << "Number space per words: " << numberOfSpacesPerWord << endl;
      cout << "Number of over space: " << numberOfOverSpace << endl;

      for (int i = 0; i < currentLineWords.size(); ++i) {
        currentLine.append(currentLineWords[i]);
        if (i < currentLineWords.size() - 1)
          currentLine.append(string(numberOfSpacesPerWord, ' '));
        if (i < numberOfOverSpace)
          currentLine.append(" ");
      }

      cout << "Current line: " << currentLine << endl;
      cout << "Current line size: " << currentLine.size() << endl;
      cout << "=========================" << endl;
      result.push_back(currentLine);
    }

    return result;
  }
};

void expect(string test, vector<string> words, int maxWidth,
            vector<string> expected) {
  Solution sol;
  vector<string> result = sol.fullJustify(words, maxWidth);
  if (result == expected) {
    cout << "\033[1m"
         << "\033[32m"
         << "PASS: " << test << "\033[0m"
         << "\033[0m" << endl;
  } else {
    cout << "\033[1m"
         << "\033[31m"
         << "FAIL: " << test << "\033[0m"
         << "\033[0m" << endl;
    cout << "-----------------------------" << endl;

    cout << "Result: \n";
    for (string cell : result)
      cout << cell << " ";
    cout << "-----------------------------" << endl;

    cout << "Expected: \n";
    for (string cell : expected)
      cout << cell << " ";
    cout << "-----------------------------" << endl;
    exit(1);
  }
}

int main() {
  expect("Test 1",
         {"This", "is", "an", "example", "of", "text", "justification."}, 16,
         {"This    is    an", "example  of text", "justification.  "});

  return 0;
}
