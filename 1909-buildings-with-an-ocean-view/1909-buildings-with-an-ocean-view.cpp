// class Solution {
// public:
//     vector<int> findBuildings(vector<int>& heights) {
//         stack<int> st;
//         vector<int> res;
//         for(int i=0;i<heights.size();i++){
//             while(!st.empty() && heights[i]>=heights[st.top()]){
//                 st.pop();
//             }
//             st.push(i);
//         }
//         while(!st.empty()){
//             res.push_back(st.top());
//             st.pop();
//         }
//         reverse(res.begin(),res.end());
//         return res;
//     }
// };
//optimized
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        int maxHeight=0;
        //iterate in reverse
        for(int i=heights.size()-1;i>=0;i--){
            if(heights[i]>maxHeight){
                maxHeight=heights[i];
                 res.push_back(i); 
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};