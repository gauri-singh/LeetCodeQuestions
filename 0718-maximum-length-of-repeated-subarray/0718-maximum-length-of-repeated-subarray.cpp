class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //this question is longest common substring question
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(nums1[i-1]==nums2[j-1]){
                    //match increment count
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=0; // continuity broke so reset to zero
                }
            }
        }
        int mx = INT_MIN;
        // cause max can be somewhere in the dp, eg maybe n=3 and m =2 is where you get the longest match 
    	for (int i = 0; i <= n; i++)
    		for (int j = 0; j <= m; j++)
    			mx = max(mx, dp[i][j]);

	return mx;
    }
};