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
    map<int,vector<int>> graph;
    void makeGraph(TreeNode* root){
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
    int amountOfTime(TreeNode* root, int start) {
        makeGraph(root);
        queue<int> q;
        unordered_map<int,int> visited;
        q.push(start);
        visited[start]=1;
        int level=-1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int currNode=q.front();
                q.pop();
                for(auto it:graph[currNode]){
                    if(visited.find(it)==visited.end()){
                        q.push(it);
                        visited[it]=1;
                    }
                }
            }
            level++;
        }
        return level;
        
    }
};