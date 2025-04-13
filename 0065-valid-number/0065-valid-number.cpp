class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit=false;
        bool seenDot=false;
        bool seenExponent=false;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                seenDigit=true;
            }
            else if(s[i]=='.'){
                //cant repeat decimal & cant have decimal after exponent
                if(seenDot || seenExponent){
                    return false;
                }
                seenDot=true;
            }
            else if((s[i]=='-' || s[i]=='+' )){
                if(i!=0 && s[i-1]!='e'&&s[i-1]!='E')
                    return false;
            }
            else if(s[i]=='e' || s[i]=='E'){
                if(seenExponent || !seenDigit){
                    return false;
                }
                seenExponent=true;
                seenDigit=false;// we need to see another digit after exponent
            }
            else{
                return false;
            }
        }
        if(!seenDigit)
            return false;
        return true;
    }
};