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
    int ans=INT_MIN;
    void maxZigZag(TreeNode* root,bool isLeft,int step){
        if(!root)
            return;
        ans=max(ans,step);
        if(isLeft){
            maxZigZag(root->right,false,step+1);
            maxZigZag(root->left,true,1);
        }
        else{
            maxZigZag(root->left,true,step+1);
            maxZigZag(root->right,false,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        maxZigZag(root,true,0);
        maxZigZag(root,false,0);
        return ans;
    }
};