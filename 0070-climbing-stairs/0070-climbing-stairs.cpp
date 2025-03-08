class Solution {
public:
vector<int> dp;
    int climbStairs(int n) {
        dp=vector<int>(n+1,-1);
        return solve(0,n);
    }
    int solve(int currStep, int n){
        if(currStep==n){
            return 1;//valid path found
        }
        if(currStep>n){
            return 0;// valid path not found
        }
        if(dp[currStep]!=-1){
            return dp[currStep];
        }
        return dp[currStep]=solve(currStep+1,n)+solve(currStep+2,n);
    }
};