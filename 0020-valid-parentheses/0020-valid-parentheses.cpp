class Solution {
public:
    bool isValid(string s) {
        unordered_map <char,char> map={
            {')','('},
            {']','['},
            {'}','{'}
        };
        stack<char> st;
        for(auto ch:s){
            if(map.count(ch) && !st.empty()){
                //closing paranthesis with non-empty stack
                if(st.top()!=map[ch]){
                    return false;
                }
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
            if(st.size()>0){
                return false;
            }
            return true;
        }
    
};