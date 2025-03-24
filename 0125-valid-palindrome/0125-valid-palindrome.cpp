class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(auto ch:s){
            if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){
                str+=tolower(ch);
            }
        }
        int l=0,r=str.size()-1;
        while(l<=r){
            if(str[l]!=str[r]){
                return false;
            }
            l++;r--;
        }
        return true;
    }
};