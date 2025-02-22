class Solution {
public:
    int calculate(string s) {
        int curr=0,prev=0;
        char currOperation='+';
        int res=0;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(isdigit(ch)){
                curr=0;
                while(isdigit(s[i]) && i<s.length()){
                    curr=curr*10+(s[i]-'0');
                    i++;
                }
                i--;// to account for an extra i++ that happened to break the while loop
                if(currOperation=='+'){
                    res+=curr;
                    prev=curr;
                }
                else if(currOperation=='-'){
                    res-=curr;
                    prev=-curr;
                }
                else if(currOperation=='*'){
                // we need to reverse previous calculation
                    res-=prev;
                    res+=prev*curr;
                    prev= prev* curr; // to store what we just calculated
                }
                else if(currOperation=='/'){
                    // we need to reverse previous calculation
                    res-=prev;
                    res+=prev/curr;
                    prev= prev/curr; // to store what we just calculated
                }

            }
            else if(ch!= ' '){
                currOperation=ch;
            }
        }
        return res;
    }
};