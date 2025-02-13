class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> lastIndex;
        for(int i=0;i<s.length();i++){
            lastIndex[s[i]]=i; // keep updating every occurance so we are left with the last index of each character at the end of the loop
        }
        int start=0,end=0;
        vector<int> res;
        for(int i=0;i<s.length();i++){
           char ch=s[i];
            end= max(end,lastIndex[ch]); 
            if(end==i){
                //we have reached end of the current partition
                res.push_back(end-start+1);
                start = end+1; // mark start of new parition
            }
        }
        return res;
    }
};