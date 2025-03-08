//tabulation
class Solution {
public:
   int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        if(n==1){
            return 1;
        }
        dp[1]=1; //1 way to reach if n =1
        dp[2]=2;// 2 ways to reach if n=2 
        for(int i=3;i<n+1;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
//space optimized:
// int climbStairs(int n) {
//         if (n <= 2) return n; // Base cases

//         int prev2 = 1; // dp[i-2]
//         int prev1 = 2; // dp[i-1]

//         for (int i = 3; i <= n; i++) {
//             int curr = prev1 + prev2; // dp[i] = dp[i-1] + dp[i-2]
//             prev2 = prev1; // Move prev1 to prev2
//             prev1 = curr; // Move curr to prev1
//         }

//         return prev1; // Final answer
//     }
// class Solution {
// public:
// // memoized: 
// vector<int> dp;
//     int climbStairs(int n) {
//         dp=vector<int>(n+1,-1);
//         return solve(0,n);
//     }
//     int solve(int currStep, int n){
//         if(currStep==n){
//             return 1;//valid path found
//         }
//         if(currStep>n){
//             return 0;// valid path not found
//         }
//         if(dp[currStep]!=-1){
//             return dp[currStep];
//         }
//         return dp[currStep]=solve(currStep+1,n)+solve(currStep+2,n);
//     }
// };