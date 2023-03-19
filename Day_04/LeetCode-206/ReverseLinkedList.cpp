// Given the head of a singly linked list, reverse the list, and return the reversed list.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]
// Example 2:


// Input: head = [1,2]
// Output: [2,1]
// Example 3:

// Input: head = []
// Output: []
 

// Constraints:

// The number of nodes in the list is the range [0, 5000].
// -5000 <= Node.val <= 5000

#include <vector>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
private:
    int listLenght(ListNode* head)
    {
        int len = 0;

        while (head != nullptr) {
            ++len;
            head = head->next;
        }
        return len;
    }

public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        int len = listLenght(head);
        std::vector<ListNode*> vec(len);
        ListNode* node = head;
        while (node != nullptr) {
            vec[--len] = node;
            node = node->next;
        }
        for (int i = 0; i < vec.size() - 1; ++i) {
            vec[i]->next = vec[i + 1];
        }
        vec[vec.size() - 1]->next = nullptr;
        head = vec[0];
        return head;
    }
};

// another solution

// class Solution {
// public:
    
//     void    swap(int& a, int& b)
//     {
//             int swap = a;
//             a = b;
//             b = swap;               
//     }
    
//     ListNode* reverseList(ListNode* head) {
//         if (!head) {
//             return (nullptr);
//         } else if(!head -> next) {
//             return (head);
//         } else if (!head -> next -> next) {
//             swap(head -> val, head -> next -> val);
//             return (head);
//         }
//         ListNode* node = head;
//         int       size = 0;
//         while (node) {
//             ++size;
//             node = node -> next;
//         }
//         node = head;
//         ListNode* tmp = head;
//         int i = 0, size2;
//         while (i < --size) {
//             size2 = size;
//             while (size2--)
//                 tmp = tmp -> next;
//             ++i;
//             swap(node -> val, tmp -> val);
//             tmp = head;
//             node = node -> next;
//         }
//         return (head);
//     }
// };
