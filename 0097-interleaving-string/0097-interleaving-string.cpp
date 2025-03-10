class Solution {
public:
  //tabulation
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(),m=s2.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        int index=0;
        if(m+n!=s3.length()){
            return false;
        }
        dp[n][m]=true;
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
               if (i < n && s1[i] == s3[i + j] && dp[i + 1][j]) {
                    dp[i][j] = true;
                }
                if (j <m && s2[j] == s3[i + j] && dp[i][j + 1]) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[0][0];
    }

    //memoization
    // vector<vector<int>> dp;
    // bool isInterleave(string s1, string s2, string s3) {
    //     int n=s1.size(),m=s2.size();
    //      dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
    //     return solve(0,0,s1,s2,s3);
    // }
    // bool solve(int i,int j,string s1, string s2, string s3 ){
    //     if(i+j==s3.size()){
    //         return (i == s1.length()) && (j == s2.length());
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     if(i<s1.length() && s1[i]==s3[i+j]){
    //         if(solve(i+1,j,s1,s2,s3)){
    //             return dp[i][j]=true;
    //         }
    //     }
    //      if( j<s2.length() && s2[j]==s3[i+j]){
    //        if(solve(i,j+1,s1,s2,s3)){
    //         return dp[i][j]= true;
    //        }
    //     }
    //     return dp[i][j]= false;
    // }
};
