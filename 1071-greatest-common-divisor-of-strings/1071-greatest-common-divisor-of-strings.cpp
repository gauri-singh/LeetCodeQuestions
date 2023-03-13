class Solution {
public:
    string findShorterString(string str1, string str2){
        if(str1.length()>str2.length()){
            return str2;
        }
        return str1;
    }
    bool checkDivision(string str1, string divisor){
        if(str1.length() %divisor.length() > 0){
            return false;
        }
        for(int i =0;i<str1.length();i++){
            if(str1[i] != divisor[(i%divisor.length())]){
                return false;
            }
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        string divisor = findShorterString(str1,str2);
        while(divisor.length()>0){
            if(checkDivision(str1,divisor) && checkDivision(str2,divisor)){
                return divisor;
            }
            divisor = divisor.substr(0, divisor.size()-1);
        }
        return "";
    }
};