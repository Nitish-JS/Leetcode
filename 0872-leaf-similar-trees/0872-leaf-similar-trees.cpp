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
    void leafNode(vector<int> &leaves,TreeNode* root){
        if(root){
            leafNode(leaves,root->left);
            leafNode(leaves,root->right);
            if(root->left==NULL && root->right==NULL){
                leaves.push_back(root->val);
            }   
        }
        return ;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;
        leafNode(leaves1,root1);
        leafNode(leaves2,root2);
        return leaves1==leaves2;
    }
};