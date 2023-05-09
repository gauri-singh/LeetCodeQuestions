class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> current;
        int left=0,right=0,ans=0;
        while(right<s.length()){
            if(current.count(s[right])){
                left++;
                right=left;
                current.clear();
            }
            else{
                current.insert(s[right]);
                int curr_len=current.size();
                ans=max(ans,curr_len);
                right++;
            }
            
        }
        return ans;
    }
};