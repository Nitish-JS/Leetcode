class Solution {
public:
    void solve(vector<string> &ans,string &digits,string &combi,int index,unordered_map<char,string> &um){
        if(index==digits.size()){
            ans.push_back(combi);
            return ;
        }
        for(auto it:um[digits[index]]){
            combi.push_back(it);
            solve(ans,digits,combi,index+1,um);
            combi.pop_back();
        }
       
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return {};
        unordered_map<char,string> um={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> ans;
        string combi="";
        solve(ans,digits,combi,0,um);
        return ans;
    }
};