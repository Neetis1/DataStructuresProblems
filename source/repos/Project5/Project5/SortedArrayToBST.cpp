

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums,0,nums.size()-1);
    }
    
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int low, int high){
        if(low > high){
            return NULL;
        }
        int mid = (low + high)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTHelper(nums,low,mid-1);
        root->right = sortedArrayToBSTHelper(nums, mid+1, high);
        return root;
    }
};
