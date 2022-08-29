/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* targetCopy=cloned;
        queue<TreeNode*> q;
        q.push(targetCopy);
        while(q.size()!=0){
            int n=q.size();
            for(int i=0;i<n;i++){
                targetCopy=q.front();
                if(targetCopy->val==target->val)
                    return targetCopy;
                q.pop();
                if(targetCopy->left)
                    q.push(targetCopy->left);
                if(targetCopy->right)
                    q.push(targetCopy->right);
            }
        }
        return NULL;
    }
};