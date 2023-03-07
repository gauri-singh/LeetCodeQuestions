class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> sellHeap;
        priority_queue<pair<int,int>,vector<pair<int,int>>> buyHeap;
        int mod=1e9+7;
        int backlog=0,sold=0;
        for(auto order: orders){
            int price=order[0];
            int quantity = order[1];
            int type =order[2];
            if(type==0){
                while(!sellHeap.empty() && quantity>0 && price>=sellHeap.top().first){
                    int sellPrice=sellHeap.top().first;
                    int sellQuantity=sellHeap.top().second;
                    sellHeap.pop();
                    sold=min(sellQuantity,quantity);
                    sellQuantity=(sellQuantity-sold+mod)%mod;
                    quantity=(quantity-sold+mod)%mod;
                    backlog=(backlog-sold+mod)%mod;
                    if(sellQuantity>0){
                        sellHeap.push({sellPrice,sellQuantity});
                    }
                }
                if(quantity>0){
                    buyHeap.push({price,quantity});
                    backlog=(backlog+quantity)%mod;
                }
            }
            else{
                while(!buyHeap.empty() && quantity>0 && price<=buyHeap.top().first){
                    int buyPrice=buyHeap.top().first;
                    int buyQuantity=buyHeap.top().second;
                    buyHeap.pop();
                    sold=min(buyQuantity,quantity);
                    buyQuantity=(buyQuantity-sold+mod)%mod;
                    quantity=(quantity-sold+mod)%mod;
                    backlog=(backlog-sold+mod)%mod;
                    if(buyQuantity>0){
                        buyHeap.push({buyPrice,buyQuantity});
                    }
                }
                if(quantity>0){
                    sellHeap.push({price,quantity});
                    backlog=(backlog+quantity)%mod;

                }
            }
        }
        return backlog;
    }
};