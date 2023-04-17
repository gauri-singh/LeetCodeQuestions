class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //if two intervals are overlapping we remove the interval with smaller end point because it has less chances of overlapping with other intervals
        
        //algorithm
        //sort the array
        //compare adjacent pairs: check if overlapping
        //if overlapping: remove the one with larger end interval value
        sort(intervals.begin(),intervals.end());
        int prevEnd =intervals[0][1];
        int count =0;
        for(int i=1;i<intervals.size();i++){
            int start =intervals[i][0];
            int end = intervals [i][1];
            if(start>=prevEnd){
                //not overlapping
               prevEnd =end;
            }
            else{
                //overlapping choose minimum larger end and effectively delete the longer interval
                count++;
                prevEnd=min(end,prevEnd);
            }
        }
        return count;
    }
};