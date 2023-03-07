class Solution {
public:
    unordered_map <char,int> createLookupTable(string str){
        unordered_map <char,int> map ;
        unordered_map <char,int>::iterator it;
        for(int i =0;i<str.length();i++){
            it = map.find(str[i]);
            if(it == map.end()){
                map[str[i]] = 1;
            }
            else 
                map[str[i]]++;
        }
        return map;
    }
    bool compareMaps( unordered_map <char,int> sMap,  unordered_map <char,int> tMap){
        unordered_map <char,int>::iterator itT;
        for(auto itS : sMap){
            itT = tMap.find(itS.first);
            if(itT == tMap.end())
                return false;
            if(itT->second != itS.second)
                return false;
        }
        return true;
    }
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map <char,int> sMap = createLookupTable(s);
       unordered_map <char,int> tMap = createLookupTable(t);
        return compareMaps(sMap,tMap);
    }
};