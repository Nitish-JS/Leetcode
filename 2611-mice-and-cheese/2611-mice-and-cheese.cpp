class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<int> diff;
        int ans=0;
        for(int i=0;i<reward1.size();i++){
            ans+=reward2[i];
            diff.push(reward1[i]-reward2[i]);
        }
        for(int i=0;i<k;i++){
            ans+=diff.top();
            diff.pop();
        }
        return ans;
    }
};