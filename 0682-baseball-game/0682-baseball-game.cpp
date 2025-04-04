class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto op : operations){
            if(op=="+"){
                int first= st.top(); st.pop();
                int second= st.top(); st.pop();
                st.push(second);st.push(first);// for original ordering
                st.push(first+second);
            }
            else if(op=="D"){
                int prev=st.top();
                st.push(prev*2);
            }
            else if(op=="C"){
                st.pop();
            }else{
                st.push(stoi(op));
            }
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();st.pop();
        }
        return sum;
    }
};