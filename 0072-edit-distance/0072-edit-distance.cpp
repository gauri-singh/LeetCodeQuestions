class Solution {
public:
//tabulation
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<m;j++){
            dp[n][j]=m-j;
        }
         for(int i=0;i<n;i++){
            dp[i][m]=n-i;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(word1[i]==word2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }else{
                    dp[i][j]=1+min({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]});
                }
            }
        }
        return dp[0][0];
    }
//Memoization
// int m,n;
// vector<vector<int>> dp;
//     int minDistance(string word1, string word2) {
//         n = word1.size(), m = word2.size();
//         dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
//         return solve(0,0,word1,word2);
//     }
//     int solve(int i, int j, string word1, string word2){
//         if (i == n) return m - j;
//         if (j == m) return n - i;
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         if(word1[i]==word2[j]){
//             return dp[i][j]=solve(i+1,j+1,word1,word2);
//         }
//         //mismatch
//         return dp[i][j]=1+ min({solve(i+1,j,word1,word2),solve(i,j+1,word1,word2),solve(i+1,j+1,word1,word2)});

//     }
};
