#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> result;

    log({"Word size: ", to_string(words.size())});
    log({"Max width: ", to_string(maxWidth)});
    log({"=================================================="});
    int lineNumber = 0;
    for (int i = 0; i < words.size();) {
      ++lineNumber;
      log({"Line number: ", to_string(lineNumber)});
      log({"I: ", to_string(i)});

      vector<string> currentLineWords;
      int totalWordsLength = 0;

      while (i < words.size() &&
             totalWordsLength + words[i].size() + currentLineWords.size() <=
                 maxWidth) {
        currentLineWords.push_back(words[i]);
        totalWordsLength += words[i].size();
        ++i;
      }

      int numberOfSpaces = maxWidth - totalWordsLength;

      int numberOfSpacesPerWord =
          currentLineWords.size() > 1
              ? numberOfSpaces / (currentLineWords.size() - 1)
              : 0;
      if (i == words.size())
        numberOfSpacesPerWord = 1;

      int numberOfOverSpace =
          numberOfSpaces -
          (numberOfSpacesPerWord) * (currentLineWords.size() - 1);

      log({"Number of words: ", to_string(currentLineWords.size())});
      log({"Total words length: ", to_string(totalWordsLength)});
      log({"Number of spaces: ", to_string(numberOfSpaces)});
      log({"Number of spaces per word: ", to_string(numberOfSpacesPerWord)});
      log({"Number of over space: ", to_string(numberOfOverSpace)});

      string currentLine = "";
      for (int j = 0; j < currentLineWords.size(); ++j) {
        currentLine.append(currentLineWords[j]);
        if (j < currentLineWords.size() - 1)
          currentLine.append(string(numberOfSpacesPerWord, ' '));

        if (i == words.size() || currentLineWords.size() == 1) {
          if (j + 1 == currentLineWords.size())
            currentLine.append(string(numberOfOverSpace, ' '));
        } else if (j < numberOfOverSpace)
          currentLine.append(" ");
      }

      log({"Current line: ", "\"" + currentLine + "\""});
      log({"Current line size: ", to_string(currentLine.size())});
      log({"=================================================="});
      result.push_back(currentLine);
    }

    return result;
  }

private:
  const int LOG_LEVEL = 0; // 0 to submit, 1 to debug
  void log(vector<string> words) {
    if (LOG_LEVEL == 1) {
      for (string word : words)
        cout << word << " ";
      cout << endl;
    }
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
         {"This", "is", "an", "example", "of", "text", "justification."},
         16,
         {"This    is    an", "example  of text", "justification.  "});

  expect("Test 2", {"What", "must", "be", "acknowledgment", "shall", "be"},
  16,
         {"What   must   be", "acknowledgment  ", "shall be        "});

  expect("Test 3",
         {"Science", "is", "what", "we", "understand", "well", "enough", "to",
          "explain", "to", "a", "computer.", "Art", "is", "everything", "else",
          "we", "do"},
         20,
         {"Science  is  what we", "understand      well",
          "enough to explain to", "a  computer.  Art is",
          "everything  else  we", "do                  "});
  return 0;
}
