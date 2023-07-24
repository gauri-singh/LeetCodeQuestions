class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int sum;
        int left, right;
        int i =0;
        for(int i =0;i<nums.size();i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            left = i+1;
            right = nums.size()-1;
            while(left<right){
                sum = nums[i]+nums[left]+nums[right];
                if(sum<0){
                    left ++;
                }
                else if(sum >0){
                    right --;
                }
                else{
                   ans.insert({nums[i],nums[left],nums[right]});
                   left++;
                   // see if next element is also same then skip because will give same output
                   // while(nums[left] == nums[left-1] && left<right){
                   //     left++;
                   // }
                }
            }
        }
        vector<vector<int>> result;
        for(auto it: ans){
            result.push_back(it);
        }
        return result;
        
    }
};