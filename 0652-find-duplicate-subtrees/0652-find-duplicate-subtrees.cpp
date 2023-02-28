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
    string solve(TreeNode* root,unordered_map<string,int> &um,vector<TreeNode*> &ans){
        if(!root)
            return "#";
        string s=solve(root->left,um,ans)+","+solve(root->right,um,ans)+","+to_string(root->val);
        um[s]++;
        if(um[s]==2)
            ans.push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        unordered_map<string,int>um;
        solve(root,um,ans);
        return ans;
    }
};