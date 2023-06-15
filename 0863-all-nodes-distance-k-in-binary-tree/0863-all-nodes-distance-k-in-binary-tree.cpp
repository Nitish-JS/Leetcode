/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int,vector<int>> graph;
    void buildGraph(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                root=q.front();
                q.pop();
                if(root->left){
                    q.push(root->left);
                    graph[root->val].push_back(root->left->val);
                    graph[root->left->val].push_back(root->val);
                }
                if(root->right){
                    q.push(root->right);
                    graph[root->val].push_back(root->right->val);
                    graph[root->right->val].push_back(root->val);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0){
            return {target->val};
        }
        buildGraph(root);
        queue<int> q;
        q.push(target->val);
        unordered_map<int,int> visited;
        visited[target->val]=1;
        int level=0;
        vector<int> ans;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int currNode=q.front();
                q.pop();
                for(auto it:graph[currNode]){
                    if(visited.find(it)==visited.end()){
                        // cout<<it<<" ";
                        q.push(it);
                        visited[it]=1;
                    }
                }
            }
            level++;
            if(level==k){
                break;
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};