class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        int total=0,index=0;
        sort(candidates.begin(),candidates.end());// to group same numbers together, since duplicate numbers in array is allowed and only those can be used, therefore the number of times x appears in array, would be the upper bound of how many times x can be used in each output vector, however permutations of same vector, i.e, same answer in different order isnt allowed
        dfs(candidates,index,total,target,curr,res);
        return res;
    }
    void dfs(vector<int>& candidates,int index,int total, int target, vector<int>& curr,vector<vector<int>>& res){
        if(total == target){
            //success;
            res.push_back(curr);
            return;
        }
        if(total>target || index>=candidates.size()){
            //out of bounds
            return;
        }
        //to take this number: take this and its duplicate which will appear next to it cause array is sorted, therefore the index is moving forward
        curr.push_back(candidates[index]);
        dfs(candidates,index+1,total+candidates[index],target,curr,res);
        //to not take means, we arent taking its duplicates as well
        curr.pop_back();

        while(index+1<candidates.size() && candidates[index]==candidates[index+1]){
            index++;
        }
        //index+1, cause the while loop stops at last instance of same number so need to move the pointer once more
        dfs(candidates,index+1,total,target,curr,res);
    }
};