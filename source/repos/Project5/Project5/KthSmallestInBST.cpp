/*Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //We will use inorder traversal as inorder traversal of a BST gives sorted array then we can go to k-1 index and get the Kth smallest element;
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        arr = BFSInorder(root,arr);
        return arr[k-1];
    }
    
    vector<int> BFSInorder(TreeNode* root , vector<int> &arr){
        if(root == nullptr) return arr;
        BFSInorder(root->left,arr);
        arr.push_back(root->val);
        BFSInorder(root->right,arr);
        return arr;
    }
    
    // iterative iorder traversal beautiful 
    int kthSmallest(TreeNode *root, int k) {
        
        stack<TreeNode*> s;

        while (true) 
        {
            while (root != nullptr)
            {
              s.push(root);
              root = root->left;
            }
            root = s.top();
            s.pop();
            if (--k == 0) return root->val;
            root = root->right;
        }
    }
};
