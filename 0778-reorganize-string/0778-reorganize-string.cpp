class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26,0);
        string res=s;
        int maxFreq=0;
        char maxChar;
        for(auto ch : s){
            count[ch-'a']++;
            if(count[ch-'a'] >maxFreq){
                maxFreq=count[ch-'a'] ;
                maxChar=ch;
            }
        }

        if(maxFreq>(s.size()+1)/2){
            return ""; // string cannot be formed
        }
        int index=0;
        while(count[maxChar-'a']!=0){
            res[index]=maxChar;
            count[maxChar-'a']--;
            index+=2;
        }
        for(int i=0;i<count.size();i++){
            while(count[i]>0){
                if(index>=s.length()){
                //the max character has filled all the even places, otherwise we continue to fill it from where it stopped
                index=1;
                }
                res[index]=i+'a';
                index+=2;
                count[i]--;
            }
        }
        return res;
    }
};