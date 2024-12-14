class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        unordered_map<int,int> :: iterator it;
        int complement;
        for(int i=0;i<nums.size();i++){
            complement=target-nums[i];
            it=map.find(complement);
            if(it!=map.end()){
                return{i,it->second};
            }
            map[nums[i]]=i; // insert with key as the number and value as the index so we can find by the key i.e, the actual number 
        }
        return {};
    }
};