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
        vector<int> level;
        vector<vector<int>> ans;
        int flag=1;
        while(q.size()!=0){
            int n=q.size();
            for(int i=0;i<n;i++){
                root=q.front();
                q.pop();
                if(root->left)
                        q.push(root->left);
                if(root->right)
                    q.push(root->right);
                level.push_back(root->val);
            }
            if(flag==1){
                ans.push_back(level);
                flag=0;
            }
            else if(flag==0){
                reverse(level.begin(),level.end());
                ans.push_back(level);
                flag=1;
            }
            level.clear();
        }
        return ans;
    }
};