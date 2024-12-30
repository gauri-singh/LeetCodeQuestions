class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //using set length
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