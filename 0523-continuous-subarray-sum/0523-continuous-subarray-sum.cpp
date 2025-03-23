class Solution {
public:
     bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>seen;// we store the remainder of the current prefix sum and index
        // intutition being- if you get same remainder again, it means that the sum of the elements in between these two indices were actually =k
        seen[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int remainder=sum%k;
            if(!seen.count(remainder) ){
                seen[remainder]=i;
            }else if (i-seen[remainder]>=2){
               return true;
            }
        }
    return false;
  }
};