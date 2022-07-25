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
    void helper(TreeNode* root,vector<string> &paths,string path){
        if(!root)
            return;
        if(root->left || root->right)
            path+=(to_string(root->val)+"->");
        else{
            path+=(to_string(root->val));
            paths.push_back(path);
        }
        helper(root->left,paths,path);
        helper(root->right,paths,path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string path="";
        helper(root,paths,path);
        return paths;
    }
};