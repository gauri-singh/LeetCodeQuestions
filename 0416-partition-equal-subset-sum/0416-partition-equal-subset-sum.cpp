class Solution {
public:
    vector<vector<bool>>dp;
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        bool ans;
        if (sum % 2 != 0) {
            return false; // cant divide odd size array into 2
        }
        // if even then we can divide the number by 2 and see if sumhalf is
        // available , if so then other half would also be available since sum
        // is cumulative sum of all numbers in the array
        sum = sum / 2;
        int n = nums.size();
        dp=vector<vector<bool>>(n + 1, vector<bool>(sum + 1, false));
        return isSubsetSum(nums,sum);
    }
    //subset sum: 
    bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        for(int i=0;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                 if(i==0){
                    dp[i][j]=false;
                }
                if(j==0){
                    dp[i][j]=true;
                }
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<target+1;j++){
                if(arr[i-1]<=j){
                    //we can choose this element
                    dp[i][j]=dp[i-1][j-arr[i-1]]|| dp[i-1][j];
                    //taking or not taking the element
                    //if taking we are reducing the current sum to be sum-currNumber
                }
                else{
                    // we cannot choose this element
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
};