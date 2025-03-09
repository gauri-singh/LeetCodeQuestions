class Solution {
public:
//Tabulation:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,1); // because every number is a LIS on its own
        for(int index=1;index<n;index++){
            for(int prevIndex=0;prevIndex<index;prevIndex++){
                //for each index, you're finding MAX LIS starting from prev index 0-index
                if(nums[index]>nums[prevIndex]){
                    dp[index]=max(dp[prevIndex]+1,dp[index]); // taking the number and incrementing the LIS count from before, or not taking the current number 
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
// vector<vector<int>> dp;
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         dp=vector<vector<int>>(n+1,vector<int>(n+1,-1));//Since prevIndex can be -1, we offset it by +1 in our table for valid indexing.
//         return solve(0,-1,nums);
//     }
//     int solve(int index,int prevIndex,vector<int>& nums){
//         if(index>=nums.size()){
//             //reached the end of vector cannot increment length anymore
//             return 0;
//         }
//         if(dp[index][prevIndex+1]!=-1){return dp[index][prevIndex+1];}
//         int taken=0;
//         if(prevIndex ==-1 || nums[index]>nums[prevIndex]){
//             //if first index or if condition is met
//             //taking current number, update previous index with current index;
//             taken = 1+solve(index+1,index,nums);
//         }
//         //not taking current number in subsequence, carry forward previous index;
//         int notTaken= solve(index+1,prevIndex,nums);
//         return dp[index][prevIndex+1]= max(taken,notTaken);
//     }
// };