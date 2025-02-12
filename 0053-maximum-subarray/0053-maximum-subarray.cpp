class Solution {
public:
// works for arrays which has atleast one positive number
    // int maxSubArray(vector<int>& nums) {
    //     int curr=0,maxSum=nums[0];
    //     for(auto num : nums ){
    //         // if(curr<0){
    //         //     curr=0;
    //         // }
    //         curr=max(curr,0); // essentially doing the comparison in one line
    //         curr+=num;
    //         maxSum=max(maxSum,curr);
    //     }
    //     return maxSum;
    // }

    //works for that + an all negative array as well
       int maxSubArray(vector<int>& nums) {
        int curr=nums[0],maxSum=nums[0];
        for(int i=1;i<nums.size();i++ ){
            int num=nums[i];
            if(num>=curr+num){
                curr=num; // if number alone is better than current sum + number
            }
            else{
                curr+=num;
            }
            maxSum=max(maxSum,curr);
        }
        return maxSum;
    }
};