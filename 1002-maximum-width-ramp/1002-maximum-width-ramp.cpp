class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // find max right for each number
        int n=nums.size();
        vector<int> maxRight(n,0);
        maxRight[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            maxRight[i]=max(maxRight[i+1],nums[i]);
        } 
        int maxWidth=0;
        int l=0,r=0; // we will use l for start of the window and r for moving the window and size
        while(l<=r && r<nums.size()){
            while(nums[l]>maxRight[r]){
                // this number doesnt have a bigger number beyond current r 
                l++;
            }
                maxWidth=max(maxWidth,r-l);
                r++;
        }
    return maxWidth;
    }
};