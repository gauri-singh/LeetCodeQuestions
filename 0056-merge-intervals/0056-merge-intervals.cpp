class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        int lastEnd,start,end;
        res.push_back(intervals[0]);
        for(auto curr: intervals){
            lastEnd=res.back()[1];
            start=curr[0];
            end=curr[1];
            if(start<=lastEnd){
                //need to merge
                res.back()[1]=max(end,lastEnd);
            }
            else{
                //non overlapping
                res.push_back(curr);
            }
        }
        return res;
    }
};