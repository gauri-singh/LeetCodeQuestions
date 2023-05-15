class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "" || s.length() < t.length()) return "";

        unordered_map<char, int> tMap, window;
        for (auto it : t) {
            tMap[it]++;
        }

        int need = tMap.size(), have = 0;
        int left = 0, right = 0, resLen = INT_MAX;
        vector<int> res(2, 0);

        for (; right < s.size(); right++) {
            char ch = s[right];
            window[ch]++;
            if (tMap.find(ch) != tMap.end() && window[ch] == tMap[ch]) {
                have++;
            }
            while (have == need) {
                if (right - left + 1 < resLen) {
                    res = {left, right};
                    resLen = right - left + 1;
                }
                window[s[left]]--;
                if (tMap.find(s[left]) != tMap.end() && window[s[left]] < tMap[s[left]]) {
                    have--;
                }
                left++;
            }
        }

        if (resLen == INT_MAX) {
            return "";
        } else {
            return s.substr(res[0], res[1] - res[0] + 1);
        }
    }
};
