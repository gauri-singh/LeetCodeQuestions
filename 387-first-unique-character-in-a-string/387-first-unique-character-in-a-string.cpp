class Solution {
public:
    unordered_map<char,int> createLookUpTable(string s){
        unordered_map<char,int> map;
        unordered_map<char,int>::iterator it;
        for(int i =0;i<s.length();i++){
           it = map.find(s[i]);
             if(it == map.end()){
                 cout<<s[i]<<endl;
                map[s[i]] = 1;
            }
            else{
                map[s[i]]++;
            }
        }
        return map;
    }
    int firstUniqChar(string s) {
        int flag = 0;
        for(int i =0;i<s.length();i++){
            flag =0;
            for(int j =0;j<s.length();j++){
                if(s[i] == s[j] && i!=j){
                    flag =1 ;
                    break;
                }
            }
            if(flag == 0)
                return i;
        }
        return -1;
//         unordered_map<char,int> map = createLookUpTable(s);
    
//         for(auto it : map){
//             if(it.second == 1)
//                 return it.first;
//         }
//         return -1;
    }
};