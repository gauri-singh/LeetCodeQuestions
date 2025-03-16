class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int index=0,i=0;// index to traverse word, i to traverser abbr
      while(i<abbr.length()){
         //is a letter 
        if(isalpha(abbr[i])){
            if(abbr[i]!=word[index]){
                return false;
            }
            i++;
            index++;
            continue;
        }
        //is a  digit 
        string num="";
        while(isdigit(abbr[i])){
            num+=abbr[i]; i++;
            if(num=="0") return false; // has leading zeros
        }
        int len=stoi(num);
        if(index+len>word.length()){
            return false; // this takes care of having 2 adjacent abbreviations
        }
        index+=len;
      }
      return index==word.length();
    }
};