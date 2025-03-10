// class Solution {
// public:
//  vector<vector<int>> dp;
//  int total_sum;
//     int findTargetSumWays(vector<int>& nums, int target) {
//         total_sum = accumulate(nums.begin(),nums.end(),0);
//         int n=nums.size();
//         dp=vector<vector<int>>(n+1,vector<int>(2*total_sum+1,-1)); // since the sum can go from -sum to plus sum 
//         return solve(0,0,target,nums);
//     }
//     int solve(int i, int total,int target, vector<int>& nums){
//          if (i == nums.size()) {
//             return total == target; // the case where total==target but all elements arent processed isnt valid
//         }
//         if(dp[i][total+total_sum]!=-1) return dp[i][total+total_sum];
//         return dp[i][total+total_sum]= solve(i+1,total+nums[i],target,nums) +
//                 solve(i+1,total-nums[i],target,nums);
//     }
// };

//Aditya verma style:
class Solution {
public:
  vector<vector<int>> dp;
  //this question is essentially count number of subset with given difference
  // some numbers have + in front and some have -
  //group together all positive numbers and sum them s1
  //group together all negative numbers and sum them, take out minus sign common we have -s2
  //therefore s1+(-s2)=target , i.e, s1-s2=diff
    int findTargetSumWays(vector<int>& arr, int target) {
        int n=arr.size();
        int diff=target;
        int total=accumulate(arr.begin(),arr.end(),0);
        //s1+s2 = total and s1-s2= diff, therefore 2s1=total+diff
        // we need to count the number of subsets that have the sum equal to this 
        if((total+diff)%2!=0 || (total+diff)<0){
            //not possible
            return 0;
        }
        int sum = (total+diff)/2;
        dp=vector<vector<int>>(n+1,vector<int>(sum+1,0));
        return countOfSubsetSum(arr,sum,n);
    }
    int countOfSubsetSum(vector<int> arr, int target,int n){
        //initialize dp
        dp[0][0] = 1;
        //If we initialize first column to 1, we are assuming there is only 1 way to make subset sum equal to 0,  i.e. null subset
        // BUT this fails if we have 0s as elements of array. 
        //If we have a single 0 present in the array, then the subsets will be '{}, {0}' whose sum will be  0.   Hence, there can be more than 1 way to make sum==0.
        // Don't initialise the first col to be 1. Everything will be initialized to 0 except the first cell in the table i.e. dp[0][0]=1. AND j will start from 0 instead of 1.

        for(int i=1;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
                }else{
                     dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
};