class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int maxAns=0;
        int ans=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i]))
                ans++;
        }
        for(int i=k;i<s.size();i++){
            maxAns=max(ans,maxAns);
            if(isVowel(s[i-k]))
                ans--;
            if(isVowel(s[i]))
                ans++;
        }
//         for(int i=s.size()-k;i<s.size();i++){
            
//         }
        maxAns=max(ans,maxAns);
        return maxAns;
    }
};