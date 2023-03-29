class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()==0){
            return true;
        }
        sort(intervals.begin(),intervals.end());
        int index =0;
        for(int i=1;i<intervals.size();i++){
            if(min(intervals[i][1],intervals[i-1][1])-max(intervals[i][0],intervals[i-1][0])>0){
                return false;
            }
        }
        return true;
    }
};