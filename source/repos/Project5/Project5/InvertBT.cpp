/*Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.*/

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
class Solution {
public:
    /* recursive solution : we will do this recursively moving to the last node where child is NULL and when the recursive calls returns a node we will store that node in a varible (we will have seperate variables for left and right subtrees) once we have the nodes returned for left and right subtree (rememeber we went upto the last node to solve this ) we will swap the nodes and return that root which will swap again at its levels left and right and move uptil the root */
    TreeNode* invertTree1(TreeNode* root) {
        if(root== NULL)
            return NULL;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
    
    /*Iterative : we can solve this iteratively also using BFS approch (going level by level ) now how will that work, to think about it might work since all we doing is mirroring the values at each level. So what we do is exactly the same we go push initially the root of the tree in the queue then we pop it swap the values of its left and right child then push these swapped left and right child values into the queue, imagine if we had not swapped these values and directly pushed them and then swapped, this would not make the its children in the correct order.Solve it once again on paper and you will definetly see the order.Now lets try to put this logic on code.9*/
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            swap(temp->left,temp->right);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return root;
    }
};
