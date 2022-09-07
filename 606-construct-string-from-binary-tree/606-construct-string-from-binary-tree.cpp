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
    string ans="";
    void traverse(TreeNode* root){
        if(!root || (root->left==NULL && root->right==NULL))
            return ;
        if(root->left){
            ans+="("+to_string(root->left->val);
            traverse(root->left);
            ans+=")";
        }
        if(root->right){
            if(!root->left)
                ans+="()";
            ans+="("+to_string(root->right->val);
            traverse(root->right);
            ans+=")";
        }
    }
    
    string tree2str(TreeNode* root) {
        ans+=to_string(root->val);
        traverse(root);
        return ans;
    }
};