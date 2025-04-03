class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxNumberOfBanana=*max_element(piles.begin(),piles.end());
        int l=1, r=maxNumberOfBanana, midRate=r+1,ans=INT_MAX;
        while(l<=r){
            midRate=(l+r)/2;
            long hours=countHours(piles, midRate);
            // we need to take more number of hours,i.e,
            //same template but reversed sign cause we are doing opposite here
            if(h>=hours){
                ans=midRate;
                r=midRate-1; // we want to reduce the rate
            }else{
                l=midRate+1;
            }
        }
        return ans;
    }
    long countHours(vector<int>& piles, int k){
        long hour=0;
        for(auto pile: piles){
            hour += (pile + k - 1) / k; 
        }
        return hour;
    }
};