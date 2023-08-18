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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        stack<TreeNode*> st;
        TreeNode* node=root;
        st.push(node);
        while(node){
            // st.push(node);
            node=st.top();
            st.pop();
            preorder.push_back(node->val);
            if(node->right)
                st.push(node->right);
            if(node->left)
                st.push(node->left);
            if(st.empty())
                break;
            
        }
        return preorder;
    }
};