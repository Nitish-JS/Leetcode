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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int width=0;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        while(q.size()!=0){
            int size=q.size();
            int first,last;
            for(int i=0;i<size;i++){
                long cur_index=q.front().second;
                TreeNode* temp=q.front().first;
                q.pop();
                if(i==0)
                    first=cur_index;
                if(i==size-1)
                    last=cur_index;
                if(temp->left)
                    q.push(make_pair(temp->left,cur_index*2+1));
                if(temp->right)
                    q.push(make_pair(temp->right,cur_index*2+2));
            }
            width=max(width,last-first+1);
        }
        return width;
    }
};