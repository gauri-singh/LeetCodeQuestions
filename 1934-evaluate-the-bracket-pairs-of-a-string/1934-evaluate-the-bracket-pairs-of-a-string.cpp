class Solution {
public:
     string evaluate(string s, vector<vector<string>>& knowledge) {
      
        unordered_map<string,string>map;
        for(vector<string>temp : knowledge){
            map[temp[0]]= temp[1];
        }  
        int open = -1, close = -1;
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(') {
                // Append the substring before the current bracket
                if (close != -1) {
                    res += s.substr(close + 1, i - close - 1);
                } else {
                    res += s.substr(0, i);
                }
                open = i;
            } else if (ch == ')') {
                close = i;
                string key = s.substr(open + 1, close - open - 1);
                if(map.count(key)){
                    res+=map[key];
                }
                else{
                    res+='?';
                }
            }
        }
        // Append the remaining substring after the last bracket
        if (close != -1) {
            res += s.substr(close + 1);
        } else {
            res = s; // If there are no brackets, return the original string
        }
        return res;
    }
};