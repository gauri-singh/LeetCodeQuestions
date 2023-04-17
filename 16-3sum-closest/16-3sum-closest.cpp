class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //sort the array
        //for every ith element start 2 pointers such that
        //left = i+1. right = nums.size()-1;
        //if sum of i,left,right> target, right-- else left++;
        sort(nums.begin(),nums.end());
        int n = nums.size(),left,right,sum;
        int ans, diff=INT_MAX;
        for(int i =0;i<n;i++){
             left = i+1;
             right = n-1;
            while(left<right){
                sum= nums[i]+nums[left]+nums[right];
                if(abs(target-sum)<diff){
                    //to find the closest
                    ans= sum;
                    diff=abs(target-sum);
                }
                if(sum == target){
                    return sum;
                }
                else if(sum>target){
                   right --;
                }
                else{
                    left++;
                }
            }
        }
        return ans;
    }
};