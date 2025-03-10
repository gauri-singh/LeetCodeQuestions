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
//different way if we took index from start
/*class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        for(int j=0;j<amount+1;j++){
            dp[n][j]=0;
        }
         for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }
        int count=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<amount+1;j++){
                if(coins[i]<=j){
                    dp[i][j]=dp[i][j-coins[i]]+dp[i+1][j];
                }else{
                    dp[i][j]=dp[i+1][j];
                }
            }
        }
        return dp[0][amount];
    }
};
memoization
class Solution {
public:
vector<vector<int>> dp;
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp=vector<vector<int>>(n+1,vector<int>(amount+1,-1));
        return solve(0,amount,coins);
    }
    int solve(int index,int amount,vector<int>& coins){
        if(index>=coins.size()){
            return 0;
        }
        if(amount==0){
            return 1; // we have found a way
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int count=0;
        if(coins[index]<=amount){
            //then we can take it and keep taking it else move on
            count+= solve(index,amount-coins[index],coins)+solve(index+1,amount,coins);
        }else{
            count+= solve(index+1,amount,coins);
        }
        return dp[index][amount] = count;
    }
};*/