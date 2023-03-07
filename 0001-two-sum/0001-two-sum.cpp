class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=nums.size()-1;j>i;j--){
        //         if(nums[i]+nums[j]== target)
        //             {
        //                 ans.push_back(i);
        //                 ans.push_back(j);
        //                 return ans;
        //             }

        //     }
        // }
        // return ans;
        unordered_map <int,int> map;
        for(int i =0;i<nums.size();i++){
            map[nums[i]] =i;
        }
        unordered_map <int,int> ::iterator it;
        int complement;
        for(int i = 0;i<nums.size();i++){
            complement = target- nums[i];
            it = map.find(complement);
            if(it !=map.end() && map[complement]!=i){
                ans.push_back(i);
                ans.push_back(map[complement]);
                return ans;
            }
        } 
        return ans;
        
    }
};