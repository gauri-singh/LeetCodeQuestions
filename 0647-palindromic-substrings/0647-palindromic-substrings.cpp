class Solution {
public:
int maxLen=0;
int count=0;
      int countSubstrings(string s) {
       for(int i=0;i<s.size();i++){
        //odd length palindromes
         // i is the center position rn and we will expand from i to see palindromes
        findPalindromes(i,i,s);
        //for checking even length palindromes
        findPalindromes(i,i+1,s);
       }
       return count;    
    }
    void findPalindromes(int l, int r,string s){
          while (l>=0 && r<s.size() && s[l]==s[r]){
            if(r-l+1 > maxLen){
                maxLen=r-l+1;
            }
            count++;
            l--;
            r++;
        }
    }
};
