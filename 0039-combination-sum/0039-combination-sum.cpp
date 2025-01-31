class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;
        int total=0,index=0;
        dfs(candidates,0,0,target,curr,res);
        return res;
    }
    void dfs(vector<int>& candidates, int index,int total,int target, vector<int>& curr, vector<vector<int>>& res){
        if(total==target){
            //success base case
            res.push_back(curr);
            return;
        }
        if(total>target || index>=candidates.size()){
            //out of bounds
            return;
        }
        //To take , add to sum but this number can be used again since unlimited duplicate use is allowed, therefore index remains same:
        curr.push_back(candidates[index]);
        dfs(candidates,index,total+candidates[index],target,curr,res);
        //To not take ,  this number can't be used now or ever, therefore index moves forward and total remains same
        curr.pop_back();
        dfs(candidates,index+1,total,target,curr,res);
    }
};