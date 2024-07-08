#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    vector<int> nums;
    for (ListNode *headNode : lists) {
      ListNode *current = headNode;
      while (current != nullptr) {
        nums.push_back(current->val);
        current = current->next;
      }
    }
    sort(nums.begin(), nums.end());
    return vectorToLinkedList(nums);
  }

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
};

int main() {
  return 0;
}
