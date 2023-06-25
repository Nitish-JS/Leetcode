class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string temp=s;
        for(int i=0;i<s.size();i++){
            temp[indices[i]]=s[i];
        }
        return temp;
    }
};