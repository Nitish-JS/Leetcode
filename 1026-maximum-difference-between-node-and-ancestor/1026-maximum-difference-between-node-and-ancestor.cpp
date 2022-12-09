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
    int helper(TreeNode* root,int maxi,int mini){
        if(!root)
            return maxi-mini;
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        return max(helper(root->left,maxi,mini),helper(root->right,maxi,mini));
    }
    int maxAncestorDiff(TreeNode* root) {
        return helper(root,INT_MIN,INT_MAX);
    }
};