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
    void inOrder(TreeNode *root,vector<int> &ans){
        if(!root)
            return ;
        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inOrder(root,ans);
        int start=0,end=ans.size()-1;
        while(start<end){
            if(ans[start]+ans[end]<k)
                start++;
            else if(ans[start]+ans[end]>k)
                end--;
            else
                return true;
        }
        return false;
        
    }
};