class Solution {
public:
vector<int> dp;
//memoization
      int numDecodings(string s) {
        dp=vector<int>(s.size()+1,-1);
        return  solve(0,s);
    }
    // we have to return number of ways
    int solve(int index, string s){
        if(index==s.size()) return 1;
        if(s[index]=='0') return 0;
        if(dp[index]!=-1) return dp[index];
        int count=0;
        count+=solve(index+1,s);// first way is taking only 1 letter
        if (index < s.size() - 1 && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6')))  {
            // there is 2 digits left in string to be considered 
           count+= solve(index+2,s); // second way is taking 2 letters if it is possible for 10-19 and 20-26
        }
        return dp[index]=count;
    }
    ////tabulation
    //   int numDecodings(string s) {
    //     int n=s.size();
    //     if(s[0]=='0'){
    //         return 0;
    //     }
    //     dp=vector<int>(n+1,0);
    //     //dp[i]== with string of length i how many ways to decode
    //     dp[0]=1; // empty string has one way to decode
    //     dp[1]=(s[0]!='0')?1:0; // a string of size 1 has 1 way to decode if it is not zero
    //     for(int i=2;i<n+1;i++){
    //         if(s[i-1]!='0'){
    //             dp[i]+=dp[i-1]; // one digit decode
    //         }
    //         if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
    //             dp[i] += dp[i - 2]; // Two-digit decode
    //         }
    //     }
    //     return  dp[n];
    // }
};