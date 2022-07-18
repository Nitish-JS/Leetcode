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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        int level_max,n;
        while(q.size()!=0){
            n=q.size();
            level_max=INT_MIN;
            for(int i=0;i<n;i++){
                root=q.front();
                q.pop();
                
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                level_max=max(level_max,root->val);
            }
            ans.push_back(level_max);
        }
        return ans;
    }
};