class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> subset;
         dfs(0,s,res,subset);
         return res;
    }
    void dfs(int index,string s, vector<vector<string>>& res, vector<string>& subset){
        if(index>=s.length()){
            //has reached end of string without any issue in this backtracking 
            res.push_back(subset);
            return;
        }
        //let's check if the string s has any palindrome possible starting from "index" position
        for(int i=index;i<s.length();i++){
            if(isPalindrome(index,i,s)){
                //s[index:i] is a palindrome lets add it to subset and see if remaining characters also form palindrome recursively
                subset.push_back(s.substr(index,i-index+1)); // since s is call by value, it wont be affected in next call
                dfs(i+1,s,res,subset);
                //take the substring out from subset for next iteration with s[index:i+1]
                subset.pop_back();
            }
        }
    }
    bool isPalindrome(int l,int r, string str){
        while(l<=r){
            if(str[l]!=str[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};