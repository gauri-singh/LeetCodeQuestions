class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>charTable (26,0);
        int l=0,r=0,ans=0,maxFreq=0;
        while(r<s.size()){
            charTable[s[r]-'A']++;
            maxFreq=max(maxFreq,charTable[s[r]-'A']);
            while((r-l+1)-maxFreq>k){
                //invalid
                charTable[s[l]-'A']--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};