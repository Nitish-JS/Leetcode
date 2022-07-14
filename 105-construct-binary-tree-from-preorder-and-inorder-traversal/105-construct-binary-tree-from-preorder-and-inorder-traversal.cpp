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
	
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inOrderMap;
        for(int i=0;i<inorder.size();i++){
            inOrderMap[inorder[i]]=i;
        }
        TreeNode *root=buildTree(preorder,0,preorder.size()-1,
                                inorder,0,inorder.size()-1,inOrderMap);
        return root;
    }
    TreeNode* buildTree(vector<int> &preorder,int preStart,int preEnd,
                       vector<int> &inorder,int inStart,int inEnd,unordered_map<int,int> &inOrderMap){
        if(preStart>preEnd || inStart>inEnd)
            return NULL;
        TreeNode *root=new TreeNode(preorder[preStart]);
        int inOrderRoot=inOrderMap[root->val];
        int numsLeft=inOrderRoot-inStart;
        root->left=buildTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inOrderRoot-1,inOrderMap);
        root->right=buildTree(preorder,preStart+numsLeft+1,preEnd,inorder,inOrderRoot+1,inEnd,inOrderMap);
        return root;
            
    }
};