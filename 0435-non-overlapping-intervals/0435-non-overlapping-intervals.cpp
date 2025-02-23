class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //if two intervals are overlapping we keep the interval with smaller end point because it has less chances of overlapping with other intervals
        
        //algorithm
        //sort the array
        //compare adjacent pairs: check if overlapping
        //if overlapping: remove the one with larger end interval value
        sort(intervals.begin(),intervals.end());
        int res=0,lastEnd=intervals[0][1],start,end;
        for(int i=1;i<intervals.size();i++){
            start= intervals[i][0];
            end= intervals[i][1];
            if(start>= lastEnd){
                //non overlapping
                lastEnd=end;
            }
            else{
                //overlapping
                lastEnd=min(lastEnd,end);// since we are keeping the one that ends first
                res++;
            }
        }
        return res;
    }
};