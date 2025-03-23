class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        // totalsum- outlier = special numbers+ result of sum of special numbers
        //total-outlier=n+n ====> we need to check if total-outlier%2==0 and if the (total-outlier)/2 is present in the array if so then it isthe outlier
        unordered_map<int, int> counts;
        int total=0;
        for(auto num: nums){
            counts[num]++;
            total+=num;
        }
        int outlier=INT_MIN;
        for(auto num:nums){
            int sum=total-num;
            if(sum%2==0){
                int special=sum/2;
                //if the current number is the special number then count needs to be>1
                if ((special == num && counts[special] > 1) || (special != num && counts.count(special))) {
                    outlier = max(outlier, num);
                }

            }
        }
        return outlier;
    }
};