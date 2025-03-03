class Solution {
public:
    vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size(), m = text2.size();
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
//  recurisve approach+ memoization - failing for one case
/*class Solution {
public:
vector<vector<int>>dp;
    int longestCommonSubsequence(string text1, string text2) {
     
       int n=text1.size(),m=text2.size();
       dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
       return lcs(text1,text2,n,m);
    }
    int lcs( string x, string y, int n, int m){
        if(n==0||m==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(x[n-1]==y[m-1]){
            //found a match increment the count
            return dp[n][m]=  1+ lcs(x,y,n-1,m-1);
        }
        else{
            //check for match in by shrinking either strings
            return dp[n][m]= max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
        }
    }
};*/