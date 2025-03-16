class Solution {
public:
    bool validPalindrome(string s) {
        int l=0, r=s.length()-1,err=0;
        while(l<=r){
            if(s[l]!=s[r]){
                //which one to move? eg eceec
                return checkPalinds(s,l,r-1) || checkPalinds(s,l+1,r); // since we only get one error allowed, we dont need to check for err counts
            } 
            l++;r--;
        }
        return true;
    }
    bool checkPalinds(string s, int l, int r){
        while(l<=r){
            if(s[l]!=s[r])
                return false;
            l++;r--;
        }
        return true;
    }
};