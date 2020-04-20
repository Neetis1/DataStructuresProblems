/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)



Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]



Note:

1 <= preorder.length <= 100
The values of preorder are distinct.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	TreeNode * insertBST(TreeNode *& root, int val)
	{
		if (root == NULL)
			root = new TreeNode(val);
		else
		{
			if (val < root->val)
				root->left = insertBST(root->left, val);
			else
				root->right = insertBST(root->right, val);
		}
		return root;
	}

	TreeNode* bstFromPreorder(vector<int>& preorder)
	{
		TreeNode * root = NULL;

		for (int index = 0; index < preorder.size(); index++)
		{
			insertBST(root, preorder[index]);
		}
		return root;
	}
};