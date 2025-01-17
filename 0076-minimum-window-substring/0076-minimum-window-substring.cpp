class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()<0){
            return "";
        }
        // needMap: stores the required frequency of each character in t
        // haveMap: stores the current frequency of each character in the window over s
        unordered_map<char,int> needMap,haveMap;
        for(auto ch: t){
            needMap[ch]++;
            haveMap[ch]=0;
        }
        int need=needMap.size();// need this for distinct characters , since we would check need and have when individual conditions for a particular character in the map is met
        int have=0,l=0,r=0,posL=0,resLen=INT_MAX;
        for(r=0;r<s.size();r++){
            char ch=s[r];
            haveMap[ch]++;
          // If this character is in needMap and we just reached the required frequency
            if (needMap.count(ch) && haveMap[ch] == needMap[ch]) {
                // We fully matched one more distinct character
                have++;
            }
            
            // If all distinct characters have been matched at least at their required frequency,
            // try to shrink the window from the left to find a smaller valid window.
            while(have==need){
                //condition fulfilled update minimum result and shrink window
                if(resLen>r-l+1){
                    resLen=r-l+1;
                    posL=l;
                }

                // Shrink the window from the left
                char leftChar = s[l];
                haveMap[leftChar]--;
                
                // If removing this character drops it below the needed frequency,
                // we lose a fully matched distinct character
                if (needMap.count(leftChar) && haveMap[leftChar] < needMap[leftChar]) {
                    have--;
                }
             
                l++; // shrink window from left
            }
        }
        return resLen==INT_MAX? "":s.substr(posL,resLen); // If we never updated resLen from INT_MAX, no valid window was found; return ""
    }
};