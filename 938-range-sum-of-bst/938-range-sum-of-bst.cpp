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
    void inorder(TreeNode* root,vector<int> &ans,int low,int high){
        if(!root)
            return ;
        inorder(root->left,ans,low,high);
        ans.push_back(root->val);
        inorder(root->right,ans,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> ans;
        inorder(root,ans,low,high);
        int range=0;
        for(int i:ans){
            if(i>=low && i<=high){
                range+=i;
            }
        }
        return range;
    }
};