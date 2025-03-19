class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen; 
        //we need to only look at previous k numbers 
        for(int i=0;i<nums.size();i++){
            if(seen.count(nums[i])){
                //we found a number that exists and is within the k distance
                return true;
            }
            seen.insert(nums[i]);
            if(seen.size()>k){
                //remove the elements that were further than k distance
                seen.erase(nums[i-k]);
            }

        }
      return false;
    }
};