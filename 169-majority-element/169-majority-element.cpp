class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int,int> map;
        unordered_map<int,int>:: iterator it;
        // for(int i=0;i<nums.size();i++){
        //     it = map.find(nums[i]);
        //     if(it == map.end()){
        //         map[nums[i]] = 1;
        //     }      
        //     else{
        //         map[nums[i]]++;
        //     }
        // }
for(auto it:nums){
    map[it]++;
}
        for( auto it : map){
            if(it.second > (nums.size()/2))
                return it.first;
        }
        return -1;
        
    }
};