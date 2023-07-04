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
    int helper(TreeNode *root,unordered_map<TreeNode*,int>& um){
        if(!root)
            return 0;
        if(um.find(root)!=um.end())
            return um[root];
        int robRoot=0;
        if(root->left){
            robRoot+=helper(root->left->left,um)+helper(root->left->right,um);
        }
        if(root->right){
            robRoot+=helper(root->right->left,um)+helper(root->right->right,um);
        }
        return um[root]=max(root->val+robRoot,helper(root->left,um)+helper(root->right,um));
    }
    int rob(TreeNode* root) {
       unordered_map<TreeNode*,int> um;
        return helper(root,um);
    }
};