class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1count (26,0);
         if(s2.size()<s1.size()){
            return false;
         }
        for(auto s :s1){
            s1count[s-'a']++;
        }
        int l=0,r=s1.size()-1;
        while(r<s2.size()){
            vector<int> s2count (26,0);
            for(int i=l;i<=r;i++){
                s2count[s2[i]-'a']++;
            }
            if(s1count==s2count){
                return true;
            }else{
                r++;l++;
            }
        }
        return false;
    }
};