class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> result;
        if(nums.size()==0){
            return {{lower,upper}};
        }
        if(nums[0]-lower>0){
            //we don't do -1 here because the result has to include lower and upper too
            result.push_back({lower,nums[0]-1});
        }
        for(int i=1;i<nums.size();i++){
            int diff=nums[i]-nums[i-1];
            if(diff>1){
                //there is a missing number
                result.push_back({nums[i-1]+1,nums[i]-1});
            }
        }
         if(upper-nums[nums.size()-1]>0){
            //we don't do -1 here because the result has to include lower and upper too
            result.push_back({nums[nums.size()-1]+1,upper});
        }
        return result;
    }
};