class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                dp[i][j]+=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};
//memoized:
// class Solution {
// public:
// vector<vector<int>>dp;
//     int uniquePaths(int m, int n) {
//         dp=vector<vector<int>>(m+1,vector<int>(n+1,-1));
//         return solve(0,0,m,n);
//     }
//     int solve(int r, int c, int m ,int n ){
//         if(r==m-1 && c==n-1){
//             return 1; // we found one way
//         }
//         if(r>=m || c>=n){
//             return 0;
//         }
//         if(dp[r][c]!=-1){ return dp[r][c];}
//         return dp[r][c]= solve(r+1,c,m,n) +solve(r,c+1,m,n);
//     }
// };
