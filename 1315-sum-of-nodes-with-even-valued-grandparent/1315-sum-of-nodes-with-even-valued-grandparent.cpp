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
    void solve(TreeNode *root,int &sum){
        if(!root)
            return;
        if(root->left  && root->val%2==0){
            if(root->left->left){
                sum+=root->left->left->val;
            }   
            if(root->left->right){
                sum+=root->left->right->val;
            }
        }
        if(root->right && root->val%2==0){
            if(root->right->left){
                sum+=root->right->left->val;
            }   
            if(root->right->right){
                sum+=root->right->right->val;
            }
        }
        solve(root->left,sum);
        solve(root->right,sum);
        
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        solve(root,sum);
        return sum;
//         BFS Approach
//         queue<pair<TreeNode*,pair<TreeNode*,TreeNode*>>> q;
//         q.push({root,{NULL,NULL}});
//         int ans=0;
//         while(!q.empty()){
//             int size=q.size();
//             for(int i=0;i<size;i++){
//                 TreeNode* root=q.front().first;
//                 TreeNode* parent=q.front().second.first;
//                 TreeNode* grandParent=q.front().second.second;
//                 q.pop();
//                 if(grandParent && (grandParent->val%2)==0)
//                     ans+=root->val;
//                 if(root->left){
//                     q.push({root->left,{root,parent}});
//                 }
//                 if(root->right){
//                     q.push({root->right,{root,parent}});
//                 }
                
//             }
//         }
//         return ans;
    }
};