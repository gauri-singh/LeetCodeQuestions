class Solution {
public:
int maxLen=0;
    string longestPalindrome(string s) {
        string res="";
       for(int i=0;i<s.size();i++){
        //odd length palindromes
         // i is the center position rn and we will expand from i to see palindromes
        findPalindromes(i,i,res,s);
        //for checking even length palindromes
        findPalindromes(i,i+1,res,s);
       }
       return res;    
    }
    void findPalindromes(int l, int r, string& res,string s){
          while (l>=0 && r<s.size() && s[l]==s[r]){
            if(r-l+1 > maxLen){
                res=s.substr(l,r-l+1);
                maxLen=r-l+1;
            }
            l--;
            r++;
        }
    }
};