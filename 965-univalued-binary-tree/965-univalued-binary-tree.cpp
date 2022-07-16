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
    bool isUnivalTree(TreeNode* root) {
        if(!root)
            return false;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0){
            int n=q.size();
            for(int i=0;i<n;i++){
                root=q.front();
                q.pop();
                if(root->left){
                    if(root->left->val!=root->val)
                        return false;
                    q.push(root->left);
                }
                if(root->right){
                    if(root->right->val!=root->val){
                        return false;
                    }
                    q.push(root->right);
                }
            }
        }
        return true;
    }
};