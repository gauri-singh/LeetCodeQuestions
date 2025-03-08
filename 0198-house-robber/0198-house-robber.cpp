class Solution {
public:

vector<int> dp;
//tabulation
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp=vector<int>(n+1,0);
         if (n == 1) return nums[0]; // Edge case: only one house
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            // only till n-1 because nums[n+1] doesn't exist
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
            // taking or not taking
        }
        //we will only fill till dp[n-1]  because nums[n] doesnt exist
        return dp[n-1];
    }
// //memoization
//     int rob(vector<int>& nums) {
//         dp=vector<int>(nums.size()+1,-1);
//         return solve(0,nums);
//     }
//     int solve(int index , vector<int> nums){
//         if(index>=nums.size()){
//             //finished going through the array
//             return 0;
//         }
//         if(dp[index]!=-1){
//             return dp[index];
//         }
//         return dp[index] = max(nums[index]+solve(index+2,nums),solve(index+1,nums));
//         //first is taking and skipping the adjacent and trying from index+2
//         //other is not taking current index and skipping it
//     }
};