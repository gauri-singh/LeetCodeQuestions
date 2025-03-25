class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1, j=num2.size()-1;
        int carry=0, total=0, rem=0;
        string str="";
        while(i>=0 || j>=0 || carry>0){
            int n1=(i>=0)?num1[i]-'0' : 0;
            int n2=(j>=0)?num2[j]-'0' : 0; // convert to int if index in bound
            total=n1+n2+carry;
            carry=total/10;
            rem=total%10;
            str+=rem+'0';// convert to char
            i--;j--;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};