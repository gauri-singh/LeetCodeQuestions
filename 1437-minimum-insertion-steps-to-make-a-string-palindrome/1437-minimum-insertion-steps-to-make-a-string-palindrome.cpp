class Solution {
public:
    int minInsertions(string s) {
        //same to same as maximum deletion to make string a palindrome
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        string s2=s;
        reverse(s2.begin(),s2.end());
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int lcs =dp[n][n];
        int insertion= n-lcs;
        return insertion; 
    }
};