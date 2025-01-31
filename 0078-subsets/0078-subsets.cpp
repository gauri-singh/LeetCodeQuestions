class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums,0,subset,res);
        return res;
    }
    void dfs(vector<int>& nums,int index, vector<int>& subset,vector<vector<int>>& res){
        if(index>=nums.size()){
            //base case, we have reached end of the nums array in one of the case so all subsets are collected for this path
            res.push_back(subset);
            return;
        }

        //to take this current number:
        subset.push_back(nums[index]);
        dfs(nums,index+1,subset,res);

        //to not take this current number in subsets:
        subset.pop_back();
        dfs(nums,index+1,subset,res);
    }
};