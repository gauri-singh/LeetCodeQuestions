class Solution {
public:
//Tabulation, this one is a little different, cause its easier to traverse the string in reverse to check for words
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool>dp(n+1,false);// dp[i] means if s[0:i] can be segmented
        dp[n] = true; // Empty string is always valid
        for(int i=n-1;i>=0;i--){
            for(auto word: wordDict){
                if(i+word.length()<n+1 && s.substr(i,word.length())==word){
                    //this is a match
                    dp[i]=dp[i+word.length()];
                }
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
};
/*Memoized
class Solution {
public: 
vector<int> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
       dp= vector<int>(s.length()+1,-1);
        return solve(0,s,wordDict);
    }
    bool solve(int index,string s,vector<string>& wordDict){
        if(index==s.length()){
            return true;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        for(auto word: wordDict){
            if(index+word.length()<=s.length() && s.substr(index,word.length()) == word){
                if(solve(index+word.length(),s,wordDict)){
                    return dp[index]=true;
                }
            }
        }
        return dp[index] =false;
    }
};*/
