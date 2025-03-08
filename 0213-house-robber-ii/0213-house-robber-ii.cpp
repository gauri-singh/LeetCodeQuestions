class Solution {
public:
    int rob(vector<int>& nums) {
         if(nums.size()==1){
            return nums[0];
        }
        // calling house robber function : including first house and not last house 
        // and then last house and not first house
        return max(houseRobber(vector<int>(nums.begin(),nums.end()-1)),houseRobber(vector<int>(nums.begin()+1,nums.end())));
    }
    int houseRobber(vector<int> nums){
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }
        int prev2=nums[0];
        int prev1=max(prev2,nums[1]);
        for(int i=2;i<nums.size();i++){
            int curr =max(nums[i]+prev2,prev1);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};