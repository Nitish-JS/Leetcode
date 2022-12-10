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
    void sumOfTree(TreeNode *root,long &totalSum){
        if(!root)
            return ;
        sumOfTree(root->left,totalSum);
        totalSum+=root->val;
        sumOfTree(root->right,totalSum);
    }
    long maxProductHelper(TreeNode* root,long &ans,long totalSum){
        if(!root)
            return 0;
        long lsum=maxProductHelper(root->left,ans,totalSum);
        long rsum=maxProductHelper(root->right,ans,totalSum);
        long subTreeSum=lsum+rsum+root->val;
        ans=max(ans,(totalSum-subTreeSum)*subTreeSum);
        return subTreeSum;
    }
    int maxProduct(TreeNode* root) {
        long totalSum=0,ans=0;
        sumOfTree(root,totalSum);
        maxProductHelper(root,ans,totalSum);
        return (int)(ans%1000000007);
    }
};