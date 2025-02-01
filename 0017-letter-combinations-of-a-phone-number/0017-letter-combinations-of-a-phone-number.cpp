class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string curr;
        vector<string> map ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.empty()){
            return result;
        }
        backtrack(0,curr,digits,result,map);
        return result;
    }
    void backtrack(int index,string& curr,string digits,vector<string>& result,vector<string>& map){
        if(index>=digits.size()){
            //reached end of digit without any problem in this recursion
            result.push_back(curr);
            return;
        }
        int currNum=digits[index]-'0';
        for(char ch: map[currNum]){
            curr+=ch;// add the current character for backtracking including ch
            backtrack(index+1,curr,digits,result,map); // recursively find the next letter corresponding to next digit
            curr.pop_back();//remove charcter ch for next iteration
        }
    }
};