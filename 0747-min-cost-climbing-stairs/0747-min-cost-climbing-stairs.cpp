class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();// it is the goal also
        vector<int>dp(n+1,0);
        for(int i=2;i<n+1;i++){
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};
//Memoization
// class Solution {
// public:
// vector<int>dp;
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();// it is the goal also
//         dp=vector<int>(n+1,-1);
//         return min(solve(0,n,cost),solve(1,n,cost));
//     }
//     int solve(int currStep,int goal,vector<int> cost){
//         if(currStep>=goal){
//             return 0;
//         }
//         if(dp[currStep]!=-1){
//             return dp[currStep];
//         }
//         return dp[currStep]= cost[currStep]+ min(solve(currStep+1,goal,cost),solve(currStep+2,goal,cost));
//     }
// };