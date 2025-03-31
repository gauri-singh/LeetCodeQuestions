class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int leftSum=0, rightSum=0; 
      int l=0,r=nums.size()-1;
      //prefixSum
      int total= accumulate(nums.begin(),nums.end(),0);
      for(int i=0;i<nums.size();i++){
            rightSum=total-nums[i]-leftSum;
            if(rightSum==leftSum){
                return i;
            }
            leftSum+=nums[i];
      }
      return -1;
    }
};