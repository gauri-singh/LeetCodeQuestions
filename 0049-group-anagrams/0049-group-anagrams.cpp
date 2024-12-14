class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //hashmap, key is the alphabetLookupVectorInStringformat
        unordered_map<string,vector<string>> map;
        for(auto str:strs){
            vector<int> count(26,0);
            for(auto ch:str){
                count[ch-'a']++;
            }
            map[convertToString(count)].push_back(str);
        }
           vector<vector<string>> res;
        for(auto it:map){
            res.push_back(it.second);
        }
        return res;
    }
    string convertToString(vector<int> count){
        string ans="";
        for(auto it:count){
            ans+=to_string(it)+",";
        }
        return ans;
    }
};