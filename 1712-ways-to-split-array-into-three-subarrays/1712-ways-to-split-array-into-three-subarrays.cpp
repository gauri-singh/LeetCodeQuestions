class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        vector<int> pre(nums);
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int res=0,mod=1e9+7;
        //given that:
        //i is the end of first array
        //j is the start of second subarray
        //k is end of second subarray
        //if we maintain the mid array we can find other two ones
        //preSum[i]<=preSum[j]-preSum[i]<=preSum[n-1]-preSum[j]
        //First: preSum[i]*2<=preSum[j]
        //second: preSum[j]*2<=preSum[n-1]+preSum[i]
        int n=nums.size();
        // we should have atleast one element in each subarray
        for(int i=0,j=0,k=0;i<n-2;i++){
            while(j<=i ||(j<n-1 && 2*pre[i]>pre[j])){
                j++;
            }
            while(k<j||(k<n-1 && 2*pre[k]<=pre[n-1]+pre[i])){
                k++;
            }
            k--;
            res=(res+k-j+1)%mod;
        }
        return res;
    }
};