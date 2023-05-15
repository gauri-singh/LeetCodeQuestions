class Solution {
public:
    int myAtoi(string s) {
        char sign='+';
        int ans=0;
        int mod = 1e9+7;
        string num;
        bool signEncountered=false;
        for(auto ch:s){
            if(ch=='-'|| ch =='+'){
                if(signEncountered || num.length() > 0){ // sign character encountered after digits or another sign
                    break;
                }
                sign = ch;
                signEncountered = true;
            }
            else if(ch>='0' && ch<='9'){
                num+=ch;
            }
            else if(ch==' '){
                if(signEncountered || num.length() > 0){ // space encountered after digits or another sign
                    break;
                }
                continue;
            }
            else{
                break;
            }
        }
        for(int i=0;i<num.length();i++){
            int digit =num[i]-'0';
           if(ans > INT_MAX/10 || (ans == INT_MAX/10 && digit > INT_MAX%10)){
                ans = sign=='-' ? INT_MIN : INT_MAX;
                return ans;
            }
            ans=(ans*10+digit);
        }
        ans = sign=='-'? ans*-1: ans;
        return ans;
    }
};