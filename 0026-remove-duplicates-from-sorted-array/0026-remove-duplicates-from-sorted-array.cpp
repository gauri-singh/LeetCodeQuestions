class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int insertIndex=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]!=nums[i]){
                //unique character
                nums[insertIndex]=nums[i];
                insertIndex++;
            }
        }
        return insertIndex;
    }
};