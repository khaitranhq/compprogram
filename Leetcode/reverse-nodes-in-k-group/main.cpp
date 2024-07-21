#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void expect_equal(string testCaseName, vector<int> a, vector<int> b) {
  if (a == b) {
  } else {
    cout << "Test case " << testCaseName << " failed!" << endl;

    cout << "Vector a: ";
    for (int x : a)
      cout << x << " ";
    cout << endl;

    cout << "Vector b: ";
    for (int x : b)
      cout << x << " ";
    cout << endl;

    assert(false);
  }
}

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    vector<ListNode *> nodes;
    ListNode *current = head;
    while (current != nullptr) {
      nodes.push_back(current);
      current = current->next;
    }

    for (int i = 0; i < nodes.size(); i += k) {

      if (i + k - 1 < nodes.size()) {
        nodes[i]->next = nodes[i + k - 1]->next;
        for (int j = 1; j < k; ++j) {
          nodes[i + j]->next = nodes[i + j - 1];
        }

        if (i - k >= 0) {
          nodes[i - k]->next = nodes[i + k - 1];
        }
      }
    }

    return nodes[k - 1];
  }
};

ListNode *vectorToLinkedList(vector<int> nums) {
  ListNode *after = nullptr;
  for (int i = nums.size() - 1; i >= 0; --i) {
    ListNode *current = new ListNode(nums[i], after);
    after = current;
    if (i == 0)
      return current;
  }
  return nullptr;
}

vector<int> linkedListToVector(ListNode *head) {
  vector<int> nums;
  while (head != nullptr) {
    nums.push_back(head->val);
    head = head->next;
  }
  return nums;
}

int main() {
  Solution solution;

  vector<int> arr, ans;
  int k;
  ListNode *head, *newHead;

  arr = {1, 2, 3, 4, 5};
  ans = {2, 1, 4, 3, 5};
  k = 2;
  head = vectorToLinkedList(arr);
  newHead = solution.reverseKGroup(head, k);
  expect_equal("1", linkedListToVector(newHead), ans);

  arr = {1, 2};
  ans = {2, 1};
  k = 2;
  head = vectorToLinkedList(arr);
  newHead = solution.reverseKGroup(head, k);
  expect_equal("2", linkedListToVector(newHead), ans);

  return 0;
}
