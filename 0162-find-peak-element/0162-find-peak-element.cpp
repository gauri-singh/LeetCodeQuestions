class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int pos=0;
        nums.push_back(INT_MIN); // so that we have neighbor to check if the size of the array is just 2 
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                return i;
            }
        }
        return pos;
    }
};