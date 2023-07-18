class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int low =newInterval[0],high=newInterval[1];
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            if(high<intervals[i][0]){
    //it comes before the rest of the intervals so just push it and return
                ans.push_back({low,high});
                ans.insert(ans.end(),intervals.begin()+i,intervals.end());
                return ans;
            }
            else if(low>intervals[i][1]){
                ans.push_back(intervals[i]);
            }
          
            else{
                low=min(intervals[i][0],low);
                high=max(intervals[i][1],high);
            }
        }
        ans.push_back({low,high});
        return ans;
    }
};