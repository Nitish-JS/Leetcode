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
    // void solve(vector<int> &answer,TreeNode *root){
    //     if(!root)
    //         return ;
    //     solve(answer,root->left);
    //     answer.push_back(root->val);
    //     solve(answer,root->right);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
         vector<int> answer;
        while(root || !st.empty() ){
            if(root){
                st.push(root);
                root=root->left;
            }
            else{
                root=st.top();
                st.pop();
                answer.push_back(root->val);
                root=root->right;
            }    
        }
        return answer;
    }
};