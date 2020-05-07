/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.



Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false


Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.*/

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

/* npw lets discuss the approach that went behind doing this solution 
we are know that our x and y cannot have the same parents and also there depth should be same, so we know we would need to find the x and y valus in
the tree first thing and then along the way calcuate depth of x , depth of y and the moment we find the values x or y we should update the 
depth and parents of x and y , we return the values the moment we find the depth of both x and y 
*/

class Solution {
public:
	bool isCousins(TreeNode* root, int x, int y) {
		int depthX = -1;
		int depthY = -1;
		int pX = 0;
		int pY = 0;
		findDepth(root, x, y, 0, depthX, depthY, pX, pY);
		if (depthX == depthY && pX != pY)
			return true;
		else return false;
	}
	void findDepth(TreeNode* root, int x, int y, int d, int &depthX, int & depthY, int & pX, int & pY){
		if (!root) return;
		if (root->left){
			if (root->left->val == x){
				depthX = d + 1;
				pX = root->val;
			}
			else if (root->left->val == y){
				depthY = d + 1;
				pY = root->val;
			}
		}
		if (root->right){
			if (root->right->val == x){
				depthX = d + 1;
				pX = root->val;
			}
			else if (root->right->val == y){
				depthY = d + 1;
				pY = root->val;
			}
		}
		if (depthX != -1 && depthY != -1)
			return;

		findDepth(root->left, x, y, d + 1, depthX, depthY, pX, pY);
		findDepth(root->right, x, y, d + 1, depthX, depthY, pX, pY);
	}
};