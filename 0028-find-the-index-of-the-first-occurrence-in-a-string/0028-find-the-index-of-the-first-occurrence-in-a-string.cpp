class Solution {
public:
    int strStr(string haystack, string needle) {
        int subSize=needle.size();
        int n=haystack.size();
        for(int i=0;i<n;i++){
            
            string temp=haystack.substr(i,subSize);
            cout<<temp<<'\n';
            if(temp==needle){
                return i;
            }
        }
        return -1;
    }
};