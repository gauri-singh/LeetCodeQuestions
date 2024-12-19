class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=0, n=heights.size();
        stack<pair<int,int>> stk; //starting index x height 
        for(int i=0;i<n;i++){
            int start = i;
            while(!stk.empty() && stk.top().second> heights[i]){
                //bounding histogram spotted, pop the higher length untill stack is non-decreasing again
                int index = stk.top().first;
                int height= stk.top().second;
                stk.pop();
                maxArea=max(maxArea,(height*(i-index)));
                start= index; // extend the starting index of current histogram to left, since bounding histogram has been popped and is not being considered anymore
            }
            stk.push({start,heights[i]});
        }
        //for elements in stack, which means, histogram unbounded on right side, can extend till n
        while(!stk.empty()){
            int index = stk.top().first;
            int height= stk.top().second;
            stk.pop();
            maxArea=max(maxArea,(height*(n-index))); 
        }
        return maxArea;
    }
};