class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=lowerBound(nums,target);
        if(first==nums.size() || nums[first]!=target){
            //number is greater than all numbers in array and doesnt exist or the lower bound is not same as the value, since target doesnt exist
            return {-1,-1};
        }
        int last =upperBound(nums,target);
       return {first,last-1};
    }
    int lowerBound(vector<int> nums, int target){
        int l=0,r=nums.size()-1,mid=nums.size(),first=nums.size();
        //lower bound: nums[i]>=target
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]>=target){
                first=mid;
                r=mid-1; // try looking for a smaller value;
            }else{
                // need bigger value
                l=mid+1;
            }
        }
        return first;
    }
    int upperBound(vector<int> nums, int target){
        int l=0,r=nums.size()-1,mid=nums.size(),last=nums.size();
         //upper bound
        while(l<=r){
                mid=l+(r-l)/2;
                if(nums[mid]>target){ // sign change cause we want first value greater than target
                    last=mid;
                    r=mid-1; // try looking for a smaller value;
                }else{
                    // need bigger value
                    l=mid+1;
                }
            }
            return last;
    }


};