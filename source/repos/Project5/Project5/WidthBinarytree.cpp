/*
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.
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
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long width = 0;
        if (nullptr == root)
            return width;
        queue<pair<TreeNode*,unsigned long long>> level;
        level.push({root,1});
        while(!level.empty()){
            int size = level.size();
            width = max(level.back().second - level.front().second +1 , width);
            
            for(int i=0;i<size;i++){
                auto node = level.front();
                level.pop();
                if(node.first->left){
                    level.push({node.first->left,2*node.second});
                }
                if(node.first->right){
                    level.push({node.first->right,2*node.second+1});
                }
            }
        }
        return width;
    }
};
