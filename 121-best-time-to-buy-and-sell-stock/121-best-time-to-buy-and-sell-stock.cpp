class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell=INT_MIN;
        int buy =INT_MAX;
        int profit =0;
        for (int i =0;i<prices.size();i++){
            if(prices[i]<buy){
                buy = prices[i];
                sell = 0;
            }
           else if(prices[i]>sell){
                sell = prices[i];
            }
            if(sell-buy > profit){
                profit = sell- buy;
            }
        }
      
    return profit;
    }
};