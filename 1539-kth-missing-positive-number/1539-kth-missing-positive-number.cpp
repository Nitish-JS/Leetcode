class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing;
        int j=1;
        for(int i=0;i<arr.size();i++){
            while(j!=arr[i]){
                missing.push_back(j++);
            }
            j++;
        }  
        if(missing.size()<k){
            for(int i=missing.size()-1;i<k;i++){
                missing.push_back(j++);
            }
        }
        // return 1;
        return missing[k-1];
    }
};