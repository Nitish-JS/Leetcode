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
    int sumEvenGrandparent(TreeNode* root) {
        queue<pair<TreeNode*,pair<TreeNode*,TreeNode*>>> q;
        q.push({root,{NULL,NULL}});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* root=q.front().first;
                TreeNode* parent=q.front().second.first;
                TreeNode* grandParent=q.front().second.second;
                q.pop();
                if(grandParent && (grandParent->val%2)==0)
                    ans+=root->val;
                if(root->left){
                    q.push({root->left,{root,parent}});
                }
                if(root->right){
                    q.push({root->right,{root,parent}});
                }
                
            }
        }
        return ans;
    }
};