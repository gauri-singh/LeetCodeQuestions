class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit=false, seenDot=false;
        if(s[0]=='+' || s[0]=='-'){
            s=s.substr(1);
        }
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(isalpha(ch)){
                if(ch!='E' && ch!='e'){
                    return false;
                }
                else{
                    return seenDigit && isInteger(s.substr(i+1));
                }
            }
            if(isdigit(ch)){
                seenDigit=true;
            }
            if(ch=='.'){
                if(seenDot){
                    return false; // dot already exists
                }
                else{
                    seenDot=true;
                }
            }
            if(ch=='+' || ch=='-'){
                return false;
            }
        }
        return seenDigit;
    }
    //this solves only integer after e
    bool isInteger(string s){
        if(s.length()==0){
            return false;
        }
        //if sign move on
        if(s[0]=='+' || s[0]=='-'){
            s=s.substr(1);
        }
        if(s.length()==0){
            return false;
        }
        for(auto ch: s){
            if(!isdigit(ch)){
                return false;
            }
        }
        return true;
    }
};