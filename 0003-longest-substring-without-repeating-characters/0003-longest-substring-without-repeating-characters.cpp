class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxCount =0;
        unordered_set <char> set;
        int left =0;int right =0;
        for(;right<s.length();right++){
            while(set.count(s[right])){
                set.erase(s[left]);
                left++;
            }
                set.insert(s[right]);
            maxCount=max(maxCount,(right-left+1));
        }
        return maxCount;
    }
};