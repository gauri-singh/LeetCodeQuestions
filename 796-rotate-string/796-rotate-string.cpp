class Solution {
public:
    //bool createSubstrings()
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }
        int n = s.length()-1;
        int i =0;
        while(n>=0){
            s = s.substr(1,s.length())+s[0];
            if(s == goal)
                return true;
            n--;
            i++; 
        }
        return false;
    }
};