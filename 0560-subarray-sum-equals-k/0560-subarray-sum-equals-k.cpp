class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> seen; // to store the sum: indices, if have we seen this sum before
        int sum=0,count=0;
        seen[0]=1;
        for(auto num: nums){
            sum+=num;
            if(seen.count(sum-k)){
                //the sum from this index to the current i will be k 
                count+=seen[sum-k];// since we have multiple numbers, multiple subarrays can have same size
            }
            seen[sum]++;
        }
        return count;
    }
};