class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxNumberOfBanana=*max_element(piles.begin(),piles.end());
        int l=1, r=maxNumberOfBanana, midRate,ans=INT_MAX;
        while(l<=r){
            midRate=(l+r)/2;
            long hours=countHours(piles, midRate);
            if(hours>h){
                //find larger rate, this was taking too much time
                l=midRate+1;
            }
            else{
                ans=min(ans,midRate);
                r=midRate-1; // found one but lets try finding even lesser rate which might achieve this
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