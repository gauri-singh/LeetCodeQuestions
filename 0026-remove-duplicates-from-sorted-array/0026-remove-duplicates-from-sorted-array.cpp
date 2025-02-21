class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       unordered_set<int> map;
       int i=0;
        for(auto num: nums){
            if(map.find(num)!=map.end()){
                continue;
            }
            map.insert(num);
            nums[i]=num;
            i++;
        }
        return map.size();
    }
};