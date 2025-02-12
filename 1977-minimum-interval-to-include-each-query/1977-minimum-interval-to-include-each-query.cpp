class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<int> sortedQ(queries);
        sort(sortedQ.begin(),sortedQ.end());
        unordered_map<int,int> result;        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minheap; //minheap
        int i=0; // pointer for intervals
        for(auto q: sortedQ){
            while(i<intervals.size() && intervals[i][0] <=q ){
                //add to heap while start of interval is before the current query
                int l = intervals[i][0];
                int r = intervals[i][1];
                minheap.push({r-l+1,r}); //<size of interval, right of interval>
                i++;
            }
            while(!minheap.empty() && minheap.top().second < q){
                // the right of interval is before current query as well, so the interval doesnt overlap with q at alll
                minheap.pop();
            }
            if(!minheap.empty()){
                result[q]=minheap.top().first; // push the size in result
            }
            else{
                 result[q]=-1;
            }
        }
        vector <int> answer; // because we need to return answer in the same order as original query array
        for(auto q: queries){
            answer.push_back(result[q]);
        }
        return answer;
    }
};