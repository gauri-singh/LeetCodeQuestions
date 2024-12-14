class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(auto ch:s){
            if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){
                str+=tolower(ch);
            }
        }
        for(int l=0,r=str.size()-1;l<r;l++,r--){
            if(str[l]!=str[r]){
                return false;
            }
        }
        return true;
    }
};