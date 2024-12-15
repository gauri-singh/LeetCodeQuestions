class Solution {
public:
    int maxArea(vector<int>& height) {
        int l,r,area=0,maxArea=0,n=height.size();
        l=0,r=n-1;
        while(l<r){
            area=(r-l)*min(height[l],height[r]);
            maxArea=max(maxArea,area);
            if(height[l]<height[r]){
                l++; // move l to maximize area;
            }
            else{
                r--;
            }
        }
        return maxArea;
    }
};