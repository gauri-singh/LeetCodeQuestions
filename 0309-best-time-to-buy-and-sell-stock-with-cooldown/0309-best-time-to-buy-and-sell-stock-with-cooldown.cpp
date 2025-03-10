class Solution {
public:

//tabulation:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2+1,0));//since we have 2 states
        int n=prices.size();
        for(int index=n-1;index>=0;index--){
            for(int state=2;state>=1;state--){
                if(state==1){
                    int buy=dp[index+1][2]- prices[index];
                    int cooldown=dp[index+1][state];
                    dp[index][state]=max(buy,cooldown);
                }else{
                    int sell=(index+2<n)?dp[index+2][1]+ prices[index]:prices[index]; // forced cool down therefore index+2. if it is the last day just add the price
                    int cooldown=dp[index+1][state];
                    dp[index][state]=max(sell,cooldown);
                }
            }
        }
        return dp[0][1];
    }
};
// class Solution {
// public:
// vector<vector<int>>dp;
// //memoized:
//     int maxProfit(vector<int>& prices) {
//         dp=vector<vector<int>>(prices.size()+1,vector<int>(2+1,-1));//since we have 2 states
//         return solve(0,1,prices);
//     }
//     int solve(int index, int state,vector<int>& prices){
//         if(index>=prices.size()){
//             return 0;
//         }
//         if(dp[index][state]!=-1){
//             return dp[index][state];
//         }
//         if(state==1){
//             //buying 
//             int buy=solve(index+1,2,prices)- prices[index]; // if we are choosing to buy convert the state for next call to selling and decrement the price from total profit
//             int cooldown=solve(index+1,state,prices);
//             return dp[index][state]=max(buy,cooldown);
//         }else{
//             //selling
//               //buying 
//             int sell=solve(index+2,1,prices)+prices[index]; // if we are choosing to sell add money made to profit, also we increment index+2 because we are forced to take a cooldown
//             int cooldown=solve(index+1,state,prices);
//             return dp[index][state]=max(sell,cooldown);
//         }
//     }
// };
