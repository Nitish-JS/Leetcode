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
    // vector<int> pre;
    int good_node=0;
    void preorder(TreeNode *root,int maxValue){
        if(!root)
            return ;
        if(root->val>=maxValue){
            good_node++;
            maxValue=root->val;
        }
        preorder(root->left,maxValue);
        preorder(root->right,maxValue);
    }
    int goodNodes(TreeNode* root) {
        preorder(root,INT_MIN);
        return good_node;
    }
};