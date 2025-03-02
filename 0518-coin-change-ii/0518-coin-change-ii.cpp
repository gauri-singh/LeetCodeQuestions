class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
          vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount + 1,0));
        //count of subset sum but for unbounded knapsack

         // Base: there's 1 way to form the amount 0 (choose no coins)
        for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1]<=j){
                    // taking the coin or not taking it
                    dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};