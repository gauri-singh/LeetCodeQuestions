class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a,b,ans=0;
        for(string token:tokens){
            if(token=="+"){
                a=st.top();st.pop();
                b=st.top();st.pop();
                st.push(a+b);
            }
            else if(token=="-"){
                a=st.top();st.pop();
                b=st.top();st.pop();
                st.push(b-a);
            }
            else if(token=="*"){
                a=st.top();st.pop();
                b=st.top();st.pop();
                st.push(a*b);
            }
            else if(token=="/"){
                a=st.top();st.pop();
                b=st.top();st.pop();
                st.push(b/a);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};