class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxLength=0,len;
        unordered_set<char> seen;
        while(r<s.size()){
            char ch=s[r];
            while(seen.count(ch)){
                seen.erase(s[l]);
                // till duplicates are available keep shrinking the window from the left side
                l++;
            }
            maxLength=max(maxLength,(r-l+1));
            seen.insert(ch);
            r++;
        }
        return maxLength;
    }
};