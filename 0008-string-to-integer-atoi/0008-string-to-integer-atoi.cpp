class Solution {
  public: int myAtoi(string s) {
    int i=0, n=s.size();

    //ignore white spaces
    while(i<n && s[i]==' '){
        i++;
    }
    int sign=1;// get sign
    if(i<n && (s[i]=='-' || s[i]=='+')){
        sign=(s[i]=='-')?-1:1;
        i++;
    }
    long result=0;
    while(i<n && isdigit(s[i])){
        result=result*10+(s[i]-'0');
        if(sign* result<=INT_MIN) return INT_MIN;
        if(sign* result>=INT_MAX) return INT_MAX;
        i++;
    }
    return result*sign;
  }
};