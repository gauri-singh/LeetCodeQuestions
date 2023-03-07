class Solution {
public:
    unordered_map<int,int> createLookupTable(vector<int> &nums){
        unordered_map <int,int> map;
        unordered_map <int,int> :: iterator it;
        for(int i =0; i < nums.size();i++){
            it= map.find(nums[i]);
            if(it == map.end()){
                map[nums[i]] = 1;
            }
            else{
                map[nums[i]]++;
            }
        }
        return map;
    }
    bool containsDuplicate(vector<int>& nums) {
       unordered_map <int,int> map = createLookupTable(nums);
        for(auto it : map){
            if(it.second > 1 )
                return true;
        }
        return false;
    }
};