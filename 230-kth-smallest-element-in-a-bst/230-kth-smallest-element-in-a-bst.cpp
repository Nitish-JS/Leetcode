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
    void inOrder(TreeNode *root,int &k,int &ans){
        if(!root)
            return ;
        inOrder(root->left,k,ans);
        if(--k==0){
            ans=root->val;
            return ;
        }
        inOrder(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inOrder(root,k,ans);
        return ans;
    }
};