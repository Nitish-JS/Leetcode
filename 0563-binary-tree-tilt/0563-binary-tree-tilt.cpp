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
    int ans=0;
    int helper(TreeNode* root){
        if(!root)
            return 0;
        int left=helper(root->left);
        int right=helper(root->right);
        ans+=abs(left-right);
        return left+right+root->val;
    }
    int findTilt(TreeNode* root) {
        helper(root);
        return ans;
    }
};