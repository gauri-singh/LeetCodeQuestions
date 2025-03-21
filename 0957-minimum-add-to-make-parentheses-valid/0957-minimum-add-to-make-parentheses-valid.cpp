class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int extra=0,open=0;
        for(auto ch:s){
            if(ch==')'){
                if(open>0){
                    open--;
                }else{
                    extra++; // extra closing paranthesis
                }
            }
            else{
                open++;
            }
        }
        return extra+open;
    }
};
/*stack approach
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count;
        for(auto ch:s){
            if(ch==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                    continue;
                }
            }
            st.push(ch);
        }
        return st.size();
    }
};*/