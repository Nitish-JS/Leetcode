class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<pair<int,int>> cap_rocks(capacity.size());
        for(int i=0;i<capacity.size();i++){
            cap_rocks[i].first=capacity[i];
            cap_rocks[i].second=rocks[i];
        }
        sort(cap_rocks.begin(),cap_rocks.end(),[](pair<int,int> &x,pair<int,int> &y){
            return (x.first-x.second)<(y.first-y.second);
        });
        int ans=0;
        for(auto it:cap_rocks){
            if(additionalRocks>=(it.first-it.second)){
                ans++;
                additionalRocks-=(it.first-it.second);
            }
        }
        return ans;
    }
    
};