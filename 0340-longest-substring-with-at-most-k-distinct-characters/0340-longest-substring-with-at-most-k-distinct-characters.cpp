class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k==0){
            return 0;
        }
          unordered_map<char,int> freqMap;
          int l=0,r=0,maxLen=0;
          while(r<s.size()){
            while(freqMap.size() >= k && !freqMap.count(s[r])){
                //if distinct=k and we have to add a new distinct character
                // we have to decrement the count of s[l] from the map and if it is =0 then we just remove teh character from map , and increment l
                freqMap[s[l]]--;
                if(freqMap[s[l]]==0){
                    freqMap.erase(s[l]);
                }
                l++;
            }
            freqMap[s[r]]++; // increment frequency of the character
            maxLen=max(maxLen,r-l+1);
            r++;
          }
          return maxLen;
    }
};