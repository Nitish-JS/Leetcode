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
   
    void rightTraversal(TreeNode *root,vector<int> &ans){
        if(!root)
            return ;
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0){
            int n=q.size();
            for(int i=0;i<n;i++){
                root=q.front();
                q.pop();
                if(root->left){
                    q.push(root->left);
                }
                if(root->right){
                    q.push(root->right);
                }
                temp.push_back(root->val);
            }
            ans.push_back(temp.back());
            temp.clear();
        }
    }
    vector<int> rightSideView(TreeNode* root) {
       vector<int> ans;
        rightTraversal(root,ans);
        return ans;
    }
};