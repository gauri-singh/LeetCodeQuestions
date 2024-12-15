class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,ans=0;
        int maxLeft = height[l], maxRight = height[r];
        while(l<r){
            if(maxLeft<=maxRight) {
                l++;
                maxLeft=max(maxLeft,height[l]);
                ans+=maxLeft-height[l];
            }
            else{
                r--;
                maxRight=max(maxRight,height[r]);
                ans+=maxRight-height[r];
            }
        }
        return ans;
    }
};