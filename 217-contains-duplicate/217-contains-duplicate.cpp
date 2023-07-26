class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        unordered_map<int,int>:: iterator it;
        for(auto it:nums){
            map[it]++;
            if(map[it]>=2){
                return true;
            }
        }
        return false;
        // for(int i = 0;i< nums.size();i++){
        //     it= map.find(nums[i]);
        //     if(it == map.end()){
        //         map[nums[i]] = 1;
        //     }
        //     else
        //         map[nums[i]]++;
        // }
        // for(auto it : map){
        //     if(it.second > 1 )
        //         return true;
        // }
        return false;
    }
};