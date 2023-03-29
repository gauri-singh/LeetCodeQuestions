class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // //min heap
        // priority_queue<int, vector<int>, greater<int>> pq;
        // int rooms =1;
        // sort(intervals.begin(),intervals.end());
        // // Create a priority queue to keep track of the end times of the meetings in the rooms.
        // pq.push(intervals[0][1]);
        // for(int i=1;i<intervals.size();i++){
        //     //if current meeting starts after the end of earliest meeting time then add it to current room itself and add it to the the heap
        //     if(intervals[i][0]>=pq.top()){
        //         pq.pop();
        //     }
        //     else{
        //         rooms++;
        //     }
        //     pq.push(intervals[i][1]);
        // }
        // return rooms;


        map<int,int> table;
        int rooms =0,currMax=0;
        for(auto it: intervals){
            table[it[0]]++;
            //since not inclusive on upper bound we dont have to add +1 like the line sweep general algo
            table[it[1]]--;
        }
        for(auto it: table){
            currMax+=it.second;
            rooms=max(rooms,currMax);
        }
        return rooms;

    }
};