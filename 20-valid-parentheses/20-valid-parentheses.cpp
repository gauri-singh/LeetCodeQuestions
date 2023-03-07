class Solution {
public:
    bool isValid(string s) {
       map<char,char> table;
       stack<char> st;
       table['}']='{';
       table[')']='(';
       table[']']='[';
       for(int i=0;i<s.length();i++){
           char ch = s[i];
           if(ch == '{' || ch== '[' ||ch=='('){
               st.push(ch);
           }
             if(ch == '}' || ch==']' ||ch==')'){
                if(st.empty())
                 return false;
                char temp =st.top();
                st.pop();
                if(temp != table[ch]){
                   return false;
               }
           }
       }
       return st.empty();
    }
};