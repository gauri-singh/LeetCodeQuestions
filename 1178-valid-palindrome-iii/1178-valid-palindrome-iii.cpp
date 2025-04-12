class Solution {
public:
 vector<vector<int>> dp;
    bool isValidPalindrome(string s, int k) {
        int n=s.length();
        dp=vector<vector<int>>(n, vector<int>(n, -1));
        return minDeletion(s,0,s.length()-1)<=k;
    }
    int minDeletion(string& s, int l, int r){
        if(l>=r){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        if(s[l]==s[r]){
            dp[l][r]= minDeletion(s,l+1,r-1);
        }else{
            dp[l][r]=1+  min(minDeletion(s,l+1,r),minDeletion(s,l,r-1));
        }
        return dp[l][r];
    }
};