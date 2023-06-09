// Given the head of a sorted linked list, 
// delete all duplicates such that each element appears only once.
// Return the linked list sorted as well.

 

// Example 1:


// Input: head = [1,1,2]
// Output: [1,2]
// Example 2:


// Input: head = [1,1,2,3,3]
// Output: [1,2,3]
 

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.


// Definition for singly-linked list.
 struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


//  Recursive solution

// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         if (head == nullptr) {
//             return nullptr;
//         }
//         if (head->next && head->val == head->next->val) {
//             ListNode* tmp = head->next;
//             head->next = tmp->next;
//             delete tmp;
//             return deleteDuplicates(head);
//         }
//         head->next = deleteDuplicates(head->next);
//         return head;
//     }
// };





class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* node = head;
        ListNode* del = nullptr;
        while (node->next != nullptr) {
            if (node->val == node->next->val) {
                del = node->next;
                node->next = del->next;
                delete del;
            } else {
                node = node->next;
            }
        }
        return head;
    }
};