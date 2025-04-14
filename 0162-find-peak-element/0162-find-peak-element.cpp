class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if ((mid == nums.size() - 1 || nums[mid + 1] < nums[mid]) &&
            (mid == 0 || nums[mid - 1] < nums[mid])){
                return mid;
            }
            //move the window where the peak is higher
            if(nums[mid+1]>nums[mid]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return 0;
    }
};