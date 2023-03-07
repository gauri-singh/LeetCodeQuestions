class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        vector<int> prefix(nums);
        int n=nums.size();
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        //preSum[i]<=preSum[j]-preSum[i]<=preSum[n-1]-preSum[j]
        //preSum[i]*2<=preSum[j] and preSum[j]*2<=preSum[n-1]+preSum[i]
        int result=0,mod=1e9+7;
        for(int i=0,j=0,k=0;i<n-2;i++){
            while(j<=i || (j<n-1 && prefix[i]*2>prefix[j])){
                j++;
            }
            //second condition is satisfied 
            while(k<j || (k<n-1 && prefix[k]*2<=prefix[n-1]+prefix[i])){
                k++;
            }
            k--;
            result=(result+k-j+1)%mod;
        }
        return result;

    }
};