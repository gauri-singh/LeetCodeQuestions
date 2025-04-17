class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int removeIdx=0,count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                swap(nums[i],nums[removeIdx]);
                removeIdx++;
               
            }
        }
        return removeIdx;
    }
};