class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        queue<int> q;
        int i;
        for(int i=1;i<n;i++){
              q.push((nums[i]+nums[i-1])%10);
        }
        n--;
        int ans=0;
        while(!q.empty() && n>0){
            for(int i=0;i<n-1;i++){
                 int a= q.front();
                q.pop();
                int b=q.front();
                q.push((a+b)%10);
            }
            ans = q.front();
            q.pop();
            n--;
        }
        return ans;
    }
};