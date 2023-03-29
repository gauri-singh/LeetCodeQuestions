class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0 , right =height.size()-1 ;
        int area, maxWater=INT_MIN;
        while(left<right){
            area=(right-left)*min(height[left],height[right]);
            maxWater=max(area,maxWater);
            if(height[right]<height[left]){
                right--;
            }
            else{
                left++;
            }
        }
        return maxWater;
    }
};