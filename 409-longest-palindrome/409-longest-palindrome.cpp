class Solution {
public:
    unordered_map <char,int> createTable(string s){
        unordered_map <char,int> map;
        unordered_map <char,int> ::iterator it;
        for(int i =0;i<s.length();i++){
            it = map.find(s[i]);
            if(it == map.end()){
                map[s[i]]=1;
            }
            else{
                map[s[i]]++;
            }
        }
        return map;
    }
    int longestPalindrome(string s) {
        if(s.length() == 1){
            return 1;
        }
        unordered_map <char,int> map = createTable(s);
        int oddCount=0;
        for (auto it: map){
            if((it.second)%2 != 0){
                oddCount++;
            }
        }
        //return (s.length() - oddCount + (oddCount >0));
        //or
       int result = oddCount>0 ? s.length()-oddCount+1 : s.length()-oddCount;
return result;
       
    }
};