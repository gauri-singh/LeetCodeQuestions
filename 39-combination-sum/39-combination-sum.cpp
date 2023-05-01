class Solution {
public:
    vector<vector<int>> res;
   void dfs(vector<int>& candidates, int target,int i,int total, vector<int> cur){
        if(total== target){
            res.push_back(cur);
            return;
        }
        if(i>=candidates.size() || total>target){
            return;
        }
        //including candidate[i]
        cur.push_back(candidates[i]);
        dfs(candidates,target,i,total+candidates[i],cur);
        //not including candidate[i]
        cur.pop_back();
        dfs(candidates,target,i+1,total,cur);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,target,0,0,{});
        return res;
    }
};