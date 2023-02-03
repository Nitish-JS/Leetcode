class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        vector<string> mat(numRows);
        int j=0;
        bool low=true;
        for(int i=0;i<s.size();i++){
            mat[j].push_back(s[i]);
            if(low){
                if(j==numRows-1){
                    j--;
                    low=false;
                }
                else{
                    j++;
                }
            }
            else{
                if(j==0){
                    j++;
                    low=true;
                }
                else{
                    j--;
                }
            }
    
        }
        string ans="";
        for(auto s:mat){
            ans+=s;
        }
        return ans;
    }
};