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
    int height(TreeNode* root){
        if(root){
            return 1+max(height(root->left),height(root->right));
        }
        return 0;
    }
    void preorder(TreeNode *root,int &ans){
        if(!root)
            return ;
       
        ans=max(ans,height(root->left)+height(root->right));
        preorder(root->left,ans);
        preorder(root->right,ans);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=INT_MIN;
        preorder(root,ans);
        return ans;
    }
};