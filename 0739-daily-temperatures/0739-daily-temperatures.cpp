// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         stack<int> st;
//         // index based stack 
//         vector<int> ans(temperatures.size(),0);
//         st.push(0);
//         for(int i=1;i<temperatures.size();i++){
//             while(!st.empty() && temperatures[i]>temperatures[st.top()]){
//                 int pos=st.top();
//                 ans[pos]=i-pos;
//                 st.pop();
//             }
//             st.push(i);
//         }
//         return ans;
//     }
// };
//using pair of index and value
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> st;
        st.push({temperatures[0],0});
        int j=0;
        for(int i=1;i<n;i++){
            while(!st.empty() && temperatures[i]>st.top().first){
                ans[st.top().second]=i-st.top().second;
                st.pop();
            }
            st.push({temperatures[i],i});
        }
        return ans;
    }
};
