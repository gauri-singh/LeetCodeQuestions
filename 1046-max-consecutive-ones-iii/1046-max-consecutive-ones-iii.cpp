class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0, right =0,maxLen=0,zeroes=0;
        if(nums.empty()){
            return 0;
        }
        while(right<nums.size()){
            if(nums[right]==0){
                zeroes++;
            }
            while(left<=right  && zeroes>k){
                if(nums[left]==0){
                    zeroes--;
                }
                left++;
            }
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};