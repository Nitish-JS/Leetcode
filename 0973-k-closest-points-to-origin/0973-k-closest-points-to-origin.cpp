class Solution {
public:
    class comparator{
        public:
        bool operator()(vector<int> &v1,vector<int> &v2){
            return (v1[0]*v1[0]+v1[1]*v1[1])<(v2[0]*v2[0] + v2[1]*v2[1]);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,comparator> pq;
        for(auto point:points){
            pq.push(point);
            if(pq.size()>k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};