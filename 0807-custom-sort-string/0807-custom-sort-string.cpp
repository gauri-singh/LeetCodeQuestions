class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26,0);
        for(auto ch: s){
            freq[ch-'a']++; // freq map;
        }
        string res;
        for(auto ch : order){
            while(freq[ch-'a']>0){
                //this character was present in string
                res+=ch;
                freq[ch-'a']--; // erase it from set since it is used
            }
        }
        for(int i=0;i<26;i++){
            while(freq[i]>0){
                res+=i+'a';
                freq[i]--; // add the remaining letters
            }
              
        }
        return res;
    }
};