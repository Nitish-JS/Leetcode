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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            root=new TreeNode(val);
            return root;
        }
            
        TreeNode *tail=NULL;
        TreeNode *p=root;
        while(p){
            tail=p;
            if(p->val<val){
                p=p->right;
            }
            else{
                p=p->left;
            }
        }
        TreeNode *temp=new TreeNode(val);
        if(tail->val<val)
            tail->right=temp;
        else
            tail->left=temp;
        return root;
    }
};