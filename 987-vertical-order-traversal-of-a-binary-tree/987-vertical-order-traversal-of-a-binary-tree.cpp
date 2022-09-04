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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode *,pair<int,int>>> traversal;
        traversal.push(make_pair(root,make_pair(0,0)));
        while(traversal.size()!=0){
            auto temp=traversal.front();
            traversal.pop();
            TreeNode *node=temp.first;
            int x=temp.second.first;
            int y=temp.second.second;
            nodes[x][y].insert(node->val);
            if(node->left){
                traversal.push(make_pair(node->left,make_pair(x-1,y+1)));
            }
            if(node->right){
                traversal.push(make_pair(node->right,make_pair(x+1,y+1)));
            }
        }
        vector<vector<int>> ans;
        for (auto it:nodes){
            vector<int> column;
            for(auto i:it.second){
                column.insert(column.end(),i.second.begin(),i.second.end());
            }
            ans.push_back(column);
        }
        return ans;
    }
};