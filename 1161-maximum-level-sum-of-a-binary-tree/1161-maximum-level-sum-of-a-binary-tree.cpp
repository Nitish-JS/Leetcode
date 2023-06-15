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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        int ans=0;
        int maxSum=INT_MIN;
        while(!q.empty()){
            int levelSum=0;
            int size=q.size();
            level++;
            for(int i=0;i<size;i++){
                root=q.front();
                q.pop();
                levelSum+=root->val;
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            if(levelSum>maxSum){
                maxSum=levelSum;
                ans=level;
            }
        }
        return ans;
        
    }
};