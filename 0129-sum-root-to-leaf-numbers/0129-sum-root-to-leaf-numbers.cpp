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
   int dfs(TreeNode *root,int ans){
       if(!root)
           return 0;
       ans=ans*10+root->val;
       if(root->left==NULL && root->right==NULL)
           return ans;
       int left=dfs(root->left,ans);
       int right=dfs(root->right,ans);
       return left+right;
   }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};