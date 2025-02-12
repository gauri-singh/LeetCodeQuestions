class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal=nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(i+nums[i]>=goal){
                //the ith value can reach goal with the jumps it has
                goal=i;
            }
        }
        return goal==0; // if goal has reached the end, it means it is possible to reach from end of array to first index, or vice versa else no
    }
};