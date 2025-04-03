class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //our binary search search space is from maxElement weight to sum of all weight
        int maxCap=accumulate(weights.begin(),weights.end(),0);
        int minCap=*max_element(weights.begin(),weights.end());
        int l=minCap, r=maxCap,midCap,ans=r+1;
        while(l<=r){
            midCap=l+(r-l)/2;
            int midDays=getNumberOfdays(weights,midCap);
            //we need to take more number of days,i.e, reduce capacity
            // using my binary search template but have to reverse the sign because of question
            if(days>=midDays){
                ans=midCap;
                r=midCap-1;// look for smaller value
            }
            else{
                l=midCap+1;
            }
        }
        return ans;
    }
    int getNumberOfdays(vector<int>& weights, int capacity){
        int days=1;
        int currCap=0;
        for(int i=0;i<weights.size();i++){
            if(currCap+weights[i]>capacity){
                days++;
                currCap=weights[i];
                continue;
            }
            currCap+=weights[i];
        }
        return days;

    }
};