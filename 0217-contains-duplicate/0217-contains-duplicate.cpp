class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());
        if(set.size()<nums.size()){
            return true;
        }
        // for(auto it:nums){
        //     if(set.count(it)){
        //         return true;
        //     }
        //     set.insert(it);
        // }
        return false;
    }
};