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
        if(!root)
            return 0;
        int max_level=1;
        int max_sum=INT_MIN;
        int level_sum=0;
        queue<TreeNode*> q;
        q.push(root);
        int i=1;
        while(q.size()!=0){
            int n=q.size();
            for(int i=0;i<n;i++){
                root=q.front();
                q.pop();
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                level_sum+=root->val;
            }
            
            if(level_sum>max_sum){
                max_sum=level_sum;
                max_level=i;
                // cout<<max_sum<<"\n";
            }
            i++;
            level_sum=0;
        }
        cout<<max_sum<<'\n';
        return max_level;
        
    }
};