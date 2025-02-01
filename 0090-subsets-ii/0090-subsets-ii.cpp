class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        dfs(0,nums,res,subset);
        return res;
    }
    void dfs(int index,vector<int>& nums,vector<vector<int>>& res,vector<int>& subset){
        if(index>=nums.size()){
            res.push_back(subset);
            return;
        }
        //to take the element
        subset.push_back(nums[index]);
        dfs(index+1,nums,res,subset);
        //to not take this element or its duplicates which are grouped together
        subset.pop_back();
        while(index+1<nums.size() && nums[index]==nums[index+1]){
            index++;
        }
       dfs(index+1,nums,res,subset);
    }
};