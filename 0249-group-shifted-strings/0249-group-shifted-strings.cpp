class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>> map;// key is difference between adjacent characters seperated by 1;
        vector<vector<string>> res;
        for(auto word: strings){
            string key="";
            for(int i=0;i+1<word.length();i++){
                int diff=((word[i+1]-word[i])+26)%26;
                // if(diff<0) diff+=26; // if difference is less than 0
                key+=to_string(diff)+"#";
            }
            map[key].push_back(word);
        }
        for(auto [key,strings] : map){
            res.push_back(strings);
        }
        return res;
    }
};