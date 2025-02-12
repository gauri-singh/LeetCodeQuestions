class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        for(int i=0;i<intervals.size();i++){
            vector<int> interval = intervals[i];
            if(newInterval[1]<interval[0]){
                //goes before current interval and we cannot have other overlaps since new interval was smaller than current one itself
                res.push_back(newInterval);
                res.insert(res.end(),intervals.begin()+i,intervals.end());
                return res;
            }
            else if( newInterval[0]> interval[1]){
                //goes after current interval
                res.push_back(interval);
                //might still be overlapping with other intervals
            }
            else{
                //overlapping
                //merge
                newInterval[0] =min(newInterval[0],interval[0]);
                newInterval[1] =max(newInterval[1],interval[1]);
            }
        }
        //if previous return isnt executed that means, new interval is larger than last interval and needs to be inserted
        res.push_back(newInterval);
        return res;
    }
};