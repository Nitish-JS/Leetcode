class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0,res=0;
        int n=chars.size();
        while(i<n){
            int grouplen=1;
            while(i+grouplen<n && chars[i+grouplen]==chars[i])
                grouplen++;
            chars[res++]=chars[i];
            if(grouplen>1){
                for(char c:to_string(grouplen)){
                    chars[res++]=c;
                }
            }
            i+=grouplen;
        }
        return res;
        
    }
};