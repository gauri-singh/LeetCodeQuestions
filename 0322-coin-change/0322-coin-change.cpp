class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    int n=coins.size();
          vector<vector<int>> dp(n + 1, vector<int>(amount + 1,INT_MAX-1));
          //dp is storing the minimum coins require to form the amount 
        //if forming the amount is not possible, we let it stay as it is 
        //count of subset sum but for unbounded knapsack

         // Base: there's 1 way to form the amount 0 (choose no coins)
        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1]<=j){
                    // taking the coin or not taking it
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                    // if taking this type of coin, increment the count of total coins
                }
                else{
                    dp[i][j]=dp[i-1][j]; // cannot take this type of coin, just copy previous value
                }
            }
        }
        return dp[n][amount] ==INT_MAX-1?-1:dp[n][amount];
    }
};