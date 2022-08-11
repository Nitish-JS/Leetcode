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
    unordered_map<int,int> mp;
public:
    void inorder(TreeNode *root){
        if(!root)
            return ;
        inorder(root->left);
        mp[root->val]++;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        int mode=INT_MIN;
        for(auto it:mp){
            mode=max(it.second,mode);
        }
        vector<int> modeArray;
        for(auto it:mp){
            if(it.second==mode){
                modeArray.push_back(it.first);
            }
        }
        return modeArray;
    }
};