class Solution {
public:
vector<vector<bool>> dp;  
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return false; // cant divide odd size array into 2
        }
        // if even then we can divide the number by 2 and see if sumhalf is available , if so then other half would also be available since sum is cumulative sum of all numbers in the array
        sum=sum/2;
        int n=nums.size();
        dp=vector<vector<bool>>(n+1,vector<bool>(sum+1,false));
        //initialization
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0){
                    dp[i][j]=false;
                }
                if(j==0){
                    dp[i][j]=true;
                }
            }
        }
        return subsetSum(nums,sum,n);
    }
    bool subsetSum(vector<int> & nums, int sum, int n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]<=j){
                    // the array is less than the sum so we can select it
                    dp[i][j]= dp[i-1][j-nums[i-1]] || dp[i-1][j];
                    //either take the number or dont take it
                    //if youre taking thenumber, we are reducing it from sum so we can find remaining numbers
                }else{
                     dp[i][j]= dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};