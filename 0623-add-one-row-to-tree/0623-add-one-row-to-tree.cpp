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
private:
    void insertRow(TreeNode* root,int val){
        TreeNode* newLeftNode=new TreeNode(val);
        TreeNode* newRightNode=new TreeNode(val);
        if(root->left){
            newLeftNode->left=root->left;
        }
        // newLeftNode->right=NULL;
        root->left=newLeftNode;
        if(root->right){
            newRightNode->right=root->right;
        }
        root->right=newRightNode;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* currNode=NULL;
        if(depth==1){
            currNode=new TreeNode(val);
            currNode->left=root;
            return currNode;
        }
        int level=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            if(level==depth-1){
                int size=q.size();
                for(int i=0;i<size;i++){
                    TreeNode *temp=q.front();
                    // cout<<temp->val<<" ";
                    q.pop();
                    insertRow(temp,val);
                }
                break;
            }
            int size=q.size();
            for(int i=0;i<size;i++){
                currNode=q.front();
                q.pop();
                if(currNode->left){
                    q.push(currNode->left);
                }
                if(currNode->right){
                    q.push(currNode->right);
                }
            }
            level++;
        }
        return root;
    }
};