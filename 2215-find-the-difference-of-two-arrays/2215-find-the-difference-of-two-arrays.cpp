class Solution {
public:
    
    vector<vector<int>> findDifference(vector<int>& a, vector<int>& b) {
        // vector<vector<int>> ans;
        set<int> a_diff_b;
        set<int> b_diff_a;
        map<int,int> mapa;
        map<int,int> mapb;
        for(int i:a){
            mapa[i]++;
        }
        for(int i:b){
            mapb[i]++;
        }
        for(int i:a){
            if(mapb.find(i)==mapb.end())
                a_diff_b.insert(i);
        }
        for(int i:b){
            if(mapa.find(i)==mapa.end())
                b_diff_a.insert(i);
        }
        vector<int> arr1;
        vector<int> arr2;
        for(int i:a_diff_b){
            arr1.push_back(i);
        }
        for(int i:b_diff_a){
            arr2.push_back(i);
        }
    
        return {arr1,arr2};
    }
};