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
    TreeNode* inPre(TreeNode *root){
        while(root && root->right!=NULL)
            root=root->right;
        return root;
    }
    TreeNode* inSuc(TreeNode *root){
        while(root && root->left!=NULL)
            root=root->left;
        return root;
    }
    int Height(TreeNode *root){
        if(!root){
            return 0;
        }
        return 1+max(Height(root->right),Height(root->left));
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
      if(root){
          if(root->val<key){
              root->right=deleteNode(root->right,key);
          }
          else if(root->val>key){
              root->left=deleteNode(root->left,key);
          }
          else{
              if(!root->left && !root->right){
                  delete root;
                  return NULL;
              }
               if (root->left==NULL^root->right==NULL)
                    return root->left ? root->left : root->right;
              TreeNode *temp=NULL;
              if(Height(root->left)>Height(root->right)){
                  temp=inPre(root->left);
                  root->val=temp->val;
                  root->left=deleteNode(root->left,temp->val);
              }
              else{
                  temp=inSuc(root->right);
                  root->val=temp->val;
                  root->right=deleteNode(root->right,temp->val);
              }
          }
      }
        
        return root;
    }
};