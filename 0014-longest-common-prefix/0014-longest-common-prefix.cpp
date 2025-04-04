class Solution {
public:
string longestCommonPrefix(vector<string>& strs) {
        //taking a random string and matching the prefix for each string for that index
        string first=strs[0],prefix="";
        for(int i=0;i<first.size();i++){
            for(auto word: strs){
                if(first[i]!=word[i]){
                    return prefix;
                }
            }
            prefix+=first[i];
        }
        return prefix;
    }
    /*string longestCommonPrefix(vector<string>& strs) {
        // have a hashmap of index-> each character on that index for each string
        int minLength=999;
        unordered_map<int,unordered_set<char>> mapping;
        for(auto word: strs){
            minLength=min(minLength,(int)(word.size()));
            for(int i=0;i<word.size();i++){
                mapping[i].insert(word[i]);
            }
        }
        //traverse the map and get the longest prefix
        int prefixCount=0;
        for(int i=0;i<minLength;i++){
            if(mapping[i].size()!=1){
                break;
            }
            prefixCount++;
        }
        if(prefixCount==0){
            return "";
        }
        string s=strs[0];
        return s.substr(0,prefixCount);;
    }*/
};