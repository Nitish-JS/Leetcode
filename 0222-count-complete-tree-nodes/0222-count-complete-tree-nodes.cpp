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

    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int left_height=1,right_height=1;
        TreeNode *left_tree=root,*right_tree=root;
        while(left_tree=left_tree->left)left_height++;
        while(right_tree=right_tree->right)right_height++;
        if(left_height==right_height) return pow(2,left_height)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    
    }
};