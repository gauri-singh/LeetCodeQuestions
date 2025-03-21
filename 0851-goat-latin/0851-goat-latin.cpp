class Solution {
public:
    string toGoatLatin(string sentence) {
        int aCount=2;
        stringstream ss(sentence);
        string token,suffix, res="";
        unordered_set<char> vowels ={'a','e','i','o','u','A','E','I','O','U'};
        while(getline(ss,token,' ')){
            suffix+='a'; // adding an extra a each iteration
            if(!vowels.count(token[0])){
                //consonant
                token=token.substr(1)+token[0];// remove first character and add it behind
            }// add 'a's
            res+=token+"ma"+suffix+" ";
        }
        res.pop_back(); // to remove extra space
        return res;
    }
};