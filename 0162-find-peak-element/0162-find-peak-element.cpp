class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.insert(nums.begin(),INT_MIN);
        nums.push_back(INT_MIN); // so that we have neighbor to check if the size of the array is just 2 
        int l=1, r=nums.size()-2;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
                return mid-1; // because we have added a -infinity in the beginning and we need to send the og index
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