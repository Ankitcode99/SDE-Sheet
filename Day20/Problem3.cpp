//Construct BST from given keys
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        return makeTree(left,right,nums);
    }
    TreeNode* makeTree(int left,int right, vector<int>& nums){
        if(left>right)
            return NULL;
        
        int mid = (left+right+1)/2;
        int val = nums[mid];
        TreeNode* root = new TreeNode(val);
        
        root->left = makeTree(left,mid-1,nums);
        root->right = makeTree(mid+1,right,nums);
        
        return root;
    }
};