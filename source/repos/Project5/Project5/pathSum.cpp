/*Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.

A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000*/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
C++ Solution: 

class Solution {
public:
       
    void pathSumHelper(TreeNode * root, int sum, vector<vector<int>>& result, vector<int>& path){
        if(root == nullptr)
            return;
        sum = sum - root->val;
        path.push_back(root->val);
        if((root->left == nullptr)  && (root->right == nullptr)  && sum == 0) 
            result.push_back(path);
        
        if(root->left) pathSumHelper(root->left,sum ,result,path);
        if(root->right) pathSumHelper(root->right,sum,result,path);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>result;
        vector<int>path;
        pathSumHelper(root,targetSum,result,path);
        return result;
    }
};
'''
class Solution:
    def pathSumHelper(self, root, Sum, path, result):
        if not root:
            return
        Sum = Sum - root.val
        path.append(root.val)
        if not root.left and not root.right and Sum == 0 :
            result.append(path[:])
        if root.left:
            self.pathSumHelper(root.left,Sum,path,result)
        if root.right:
            self.pathSumHelper(root.right,Sum,path,result)
        path.pop()
            
            
    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
        path =[];
        result = [];
        self.pathSumHelper(root,targetSum,path,result)
        return result
        
    
