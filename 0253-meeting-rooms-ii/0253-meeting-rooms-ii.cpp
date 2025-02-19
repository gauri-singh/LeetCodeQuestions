class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start,end;
        for(auto interval: intervals){
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int res=0,s=0,e=0;
        int rooms=0;
        while(s<intervals.size()){
            if(start[s]<end[e]){
                rooms++;
                res=max(rooms,res);
                s++;
            }
            else{
                rooms--;
                e++;
            }
        }
        return res;
    }
};