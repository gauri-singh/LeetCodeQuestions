class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int total=accumulate(nums.begin(),nums.begin()+k,0);
        double sum=total;
        int l=0;
        for(int r=k;r<nums.size();r++){
            total=total+nums[r]-nums[l];// cn also do nums[i]-nums[i-k];
            if(sum<total){
                sum=total;
            }
            l++;
        }
        return sum/k;
    }
};