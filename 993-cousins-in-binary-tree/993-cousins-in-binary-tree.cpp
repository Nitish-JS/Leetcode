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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)
            return false;
        queue<TreeNode*> q;
        unordered_map<int,int> mp;
        q.push(root);
        while(q.size()!=0){
            int n=q.size();
            for(int i=0;i<n;i++){
                root=q.front();
                q.pop();
                if(root->left){
                    mp[root->left->val]=root->val;
                    q.push(root->left);
                }
                if(root->right){
                    mp[root->right->val]=root->val;
                    q.push(root->right);
                }
            }
            if(mp.find(x)!=mp.end() && mp.find(y)!=mp.end() && mp[x]!=mp[y])
                    return true;
            mp.clear();
        }
        return false;
    }
};