#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
LeetCode 21 - Merge Two Sorted Lists

Approach:
- Create a dummy node to simplify merging.
- Compare the current nodes of both linked lists.
- Attach the smaller node to the merged list.
- Move the corresponding list pointer forward.
- Once one list is exhausted, attach the remaining nodes.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(-1);
        ListNode* temp = &dummy;

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        temp->next = (list1 != nullptr) ? list1 : list2;

        return dummy.next;
    }
};

// Function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // List 1: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // List 2: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution obj;
    ListNode* ans = obj.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(ans);

    return 0;
}