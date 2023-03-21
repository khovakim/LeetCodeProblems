// Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

// Example 1:


// Input: root = [1,null,2,3]
// Output: [1,3,2]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]
 

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100


#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


//  Recursive solution

// class Solution {
//     void inorderTraversalRec(TreeNode* root, std::vector<int>& inorderTree)
//     {
//         if (root == nullptr) {
//             return ;
//         }
//         inorderTraversalRec(root->left, inorderTree);
//         inorderTree.push_back(root->val);
//         inorderTraversalRec(root->right, inorderTree);
//     }
// public:
//     std::vector<int> inorderTraversal(TreeNode* root) {
//         std::vector<int> inorderTree;
//         inorderTraversalRec(root, inorderTree);
//         return inorderTree;
//     }
// };

#include <stack>

//  Iterative solution

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> inorderTree;
        if (root == nullptr) {
            return inorderTree;
        }
        std::stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr != nullptr || st.empty() == false) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            inorderTree.push_back(curr->val);
            curr = curr->right;
        }
        return inorderTree;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)