class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        // index based stack 
        vector<int> ans(temperatures.size(),0);
        st.push(0);
        for(int i=1;i<temperatures.size();i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                int pos=st.top();
                ans[pos]=i-pos;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};