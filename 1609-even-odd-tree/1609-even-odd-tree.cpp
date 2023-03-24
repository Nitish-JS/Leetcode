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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        int prev=INT_MIN;
        while(!q.empty()){
            int size=q.size();
            if(level%2==0){
                prev=INT_MIN;
            }
            else{
                prev=INT_MAX;
            }
            for(int i=0;i<size;i++){
                root=q.front();
                q.pop();
                if(level%2==0){
                    if(root->val%2==1 && root->val>prev){
                        prev=root->val;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if(root->val%2==0 && root->val<prev){
                        prev=root->val;
                    }
                    else{
                        return false;
                    }
                }
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            level++;
        }
        return true;
    }
};