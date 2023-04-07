class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // prefix sum : count -> map
        unordered_map<int,int>map;
        unordered_map<int,int> :: iterator it;
        int sum =0,cnt=0,target;
        //base case empty sub array, when you're taking the entire subarray 
        map[0]=1;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            target =sum-k;
            //since we are going linearly and not pre calculating the prefix sum
            // we know that the target would exist only if it in the current subarray starting from i
            
            it = map.find(target);
            if(it!=map.end()){
                cnt+=map[target];
            }
            map[sum]++;
        }
        return cnt;
    }
};