class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digits,res;
        vector<pair<string,string>> letters;
        for(auto str: logs){
            int i=0;
            while(str[i]!=' '){
                i++; // to find the first white space so we can split the key from the logs
            }
            if(isalpha(str[i+1])){
                letters.push_back({str.substr(0,i),str.substr(i+1)}); // pushing as a pair log key and the value
            }else{
                digits.push_back(str);
            }
        }
        sort(letters.begin(),letters.end(),[](auto& a, auto& b){
            return a.second==b.second? a.first<b.first : a.second<b.second;
        });
        for(auto& pair : letters){
            res.push_back(pair.first+" "+pair.second);
        }
        res.insert(res.end(),digits.begin(),digits.end());
        return res;
    }
};