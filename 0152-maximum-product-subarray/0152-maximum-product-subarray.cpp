class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res= nums[0];
        int currMax=1,currMin=1;
        for(int num: nums){
            //this if case is redundant
            if(num==0){
                currMin=1;currMax=1;
            }
            int oldMax=currMax;
            //you can find max of 3 numbers using 2 nested max or max({a,b,c,d})
            currMax=max({num,currMin*num,currMax*num});
            currMin=min({num,currMin*num,oldMax*num});
            res=max({res,currMax,currMin});
        }
        return res;
    }
};