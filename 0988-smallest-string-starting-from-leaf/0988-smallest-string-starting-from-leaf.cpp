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
    void dfs(TreeNode* root,string &ans,string temp){
        if(!root)
            return ;
        temp=(char)(root->val+'a')+temp;
        if(root->left==NULL && root->right==NULL){
            if(ans=="")
                ans=temp;
            else
                ans=min(temp,ans);
        }
        
        dfs(root->left,ans,temp);
        dfs(root->right,ans,temp);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans="";
        dfs(root,ans,"");
        return ans;
    }
};