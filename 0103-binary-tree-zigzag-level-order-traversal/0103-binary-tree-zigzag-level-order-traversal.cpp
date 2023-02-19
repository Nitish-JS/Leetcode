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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        
        vector<vector<int>> ans;
        int flag=1;
        while(q.size()!=0){
            int n=q.size();
            vector<int> level(n);
            for(int i=0;i<n;i++){
                root=q.front();
                q.pop();
                int index=flag?i:(n-i-1);
                level[index]=root->val;
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                
            }
            flag=!flag;
            ans.push_back(level);
        }
        return ans;
    }
};