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
    int height(TreeNode* root,int &ans){
        if(root){
            int left_height=height(root->left,ans);
            int right_height=height(root->right,ans);
            ans=max(ans,left_height+right_height);
            return 1+max(left_height,right_height);
        }
        return 0;
    }
//     void preorder(TreeNode *root,int &ans){
//         if(!root)
//             return ;
       
//         ans=max(ans,height(root->left)+height(root->right));
//         preorder(root->left,ans);
//         preorder(root->right,ans);
        
//     }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=INT_MIN;
        height(root,ans);
        return ans;
    }
};