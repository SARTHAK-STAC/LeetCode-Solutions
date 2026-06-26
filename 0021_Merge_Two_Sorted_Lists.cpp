#include <cstddef>
using namespace std;

/*
LeetCode 21 - Merge Two Sorted Lists

Approach:
Use a dummy node to simplify the merging process.
- Compare the current nodes of both linked lists.
- Attach the smaller node to the merged list.
- Move the corresponding pointer forward.
- Continue until one list is exhausted.
- Attach the remaining nodes of the other list.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1 != NULL)
            temp->next = list1;
        else
            temp->next = list2;

        return dummy->next;
    }
};