class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "" || s.length()<t.length()) return "";
        unordered_map <char,int> tMap,window;
        for(auto it:t){
            tMap[it]++;
        }
        //need should have UNIQUE characters in t, therefore:
        int need=tMap.size(),have=0; 
        int left=0,right=0,resLen=INT_MAX;
        vector <int> res(2,0);
        for(;right<s.size();right++){
            char ch =s[right];
            window[ch]++;
            if(tMap.find(ch)!=tMap.end() && window[ch]==tMap[ch]){
                have++;
            }
            while(have==need){
                if(right-left+1 < resLen){
                    res={left,right};
                    resLen=right-left+1;
                }
                //if the condition is met we keep shrinking from left
                window[s[left]]--;
                //did we make it less after removing the character
                if(tMap.find(s[left])!=tMap.end() && window[s[left]]<tMap[s[left]]){
                have--;
            }
                left++;
            }//while loop
        }
        // when s and t are of same size but different characters so that the loop didnt even execute
        if(resLen==INT_MAX)
            return "";
        return s.substr(res[0],res[1]-res[0]+1);

    }
};