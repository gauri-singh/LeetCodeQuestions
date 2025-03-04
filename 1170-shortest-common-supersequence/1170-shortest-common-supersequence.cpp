class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        //similar to print lcs question
        int n=str1.size(),m=str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string scs="";
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                scs+=str1[i-1];
                i--;j--;
            }
            else{
                  if(dp[i-1][j]>dp[i][j-1]){
                    
                    scs+=str1[i-1];// we add the character of the string whos index we are moving
                    i--;
                  }else{
                    scs+=str2[j-1];
                    j--;
                  }
            }
        }
        while (i > 0) {
            scs += str1[i - 1]; // take remaining character from str1
            i--;
	    }

        while (j > 0) {
            scs += str2[j - 1];  // take remaining character from str2
            j--;
        }
        reverse(scs.begin(),scs.end());
        return scs;
    }
};