class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1,mid,ans=nums[0];
        while(l<=r){
            if(nums[l]<=nums[r]){
                //left to right is sorted
                ans=min(ans,nums[l]);
            }
            mid=(l+r)/2;
            ans=min(ans,nums[mid]);
            if(nums[l]<=nums[mid]){
                //first sub array, all elements in second sub array are smaller than first sub array so just search in right direction
                l=mid+1;
            }
            else{
                //all elements to right of mid is larger, therefore just search in left direction
                r=mid-1;
            }
        }
        return ans;
    }
};