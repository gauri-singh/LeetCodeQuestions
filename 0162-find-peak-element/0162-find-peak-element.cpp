class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int pos=0;
        nums.push_back(INT_MIN);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                return i;
            }
        }
        return pos;
    }
};