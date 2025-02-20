class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> lookup;
        for(char ch: s){
            lookup[ch]++;
        }
        for(int i=0;i<s.length();i++){
            if(lookup[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};