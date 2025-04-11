class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.length();i++){
            int k=i;
            int j=0;
            while(k<haystack.length()&& j<needle.length() && haystack[k]==needle[j]){
                k++;
                j++;
            }
            if(j==needle.length()){
                return i;
            }
        }
        return -1;
    }
};