class Solution {
public:
    int search(vector<int>& nums, int target) {
       int left=0,right=nums.size()-1,mid;
       while(left<=right) {
        mid=(left+right)/2;
        //find which subarray we are part of
        if(nums[left]<=nums[mid]){
            //first sorted array
            if(target>nums[mid]){
                //can only be in right
                left=mid+1;
            }
            else if(target<nums[mid]){
                if(target<nums[left]){
                    //smaller than smallest element of first sub array, look in right
                    left=mid+1;
                }
                else{
                    //target is between 0 and mid
                    right=mid-1;
                }
            }
            else{
                return mid;
            }
        }
        else{
            //second sorted array
            if(target<nums[mid]){
                //can only be in left
                right=mid-1;
            }
            else if(target>nums[mid]){
                if(target>nums[right]){
                    //larger than largest element of second sub array, look in left
                    right=mid-1;
                }
                else{
                    //target is between mid and n-1;
                    left=mid+1;
                }
            }
            else{
                return mid;
            }
        }
       }//while
       return -1;
    }
};
