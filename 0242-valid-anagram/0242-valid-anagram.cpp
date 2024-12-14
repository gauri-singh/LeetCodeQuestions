class Solution {
public:
    bool isAnagram(string s, string t) {
        //we can use two maps and directly compare if they are same
        //optimized method is using a alphabetLookupVector
      
        if(s.length()!=t.length()){
            return false;
        }
          vector<int>count(26,0);
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        //if anagram each count[i] should be zero after the completion of above loop
        for(auto it:count){
            if(it!=0)
                return false;
        }
        return true;
    }
};