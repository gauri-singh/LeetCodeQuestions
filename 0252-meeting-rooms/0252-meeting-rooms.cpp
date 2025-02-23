class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return true;
        }
        sort(intervals.begin(),intervals.end()); // sorting by the start value
        int lastEnd=intervals[0][1];// end time for the last meeting
        for(int i=1;i<intervals.size();i++){
            int start= intervals[i][0];
            int end = intervals[i][1];
            if(start>=lastEnd){
                //no overlap
                lastEnd=end;
            }
            else{
                return false;
            }
        }
        return true;
    }
};