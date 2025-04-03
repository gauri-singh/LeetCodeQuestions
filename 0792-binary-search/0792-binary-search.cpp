class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int ans=r+1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(target<=nums[mid]){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(ans>=nums.size()){
            return -1;
        }
        return nums[ans]==target? ans: -1;
    }
};