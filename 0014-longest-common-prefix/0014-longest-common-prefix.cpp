class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string word, prefix= "";
        int cnt =0,index=0;
        char i='a';
        while(i<='z'){
            cnt = 0;
            cout<<"the prefix is "<<prefix<<endl;
            for(int j=0;j<strs.size();j++){
                word = strs[j];
                if(word[index] != i){
                    cnt=1;
                    break;
                }
            }
            if(cnt == 0){
                prefix+=i;
                i='a';
                index++;
            }
            else{
                //check for next alphabet
            i++;
            }
            
        }
        return prefix;
    }    
};