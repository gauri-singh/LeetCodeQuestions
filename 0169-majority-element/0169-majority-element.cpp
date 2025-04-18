class Solution {
public:
//boyer moore voting algo
    int majorityElement(vector<int>& nums) {
        int candidate=nums[0], count=0;
        for(auto n: nums){
            if(n==candidate){
                count++;
            }else{
                count--;
            }
            if(count<0){
                candidate=n;
                count=1;
            }
        }
        return candidate;
    }
   /* int majorityElement(vector<int>& nums) {
        int res=0, maxCount=0;
        unordered_map<int,int>freq;
        for(auto n: nums){
            freq[n]++;
            if(freq[n] > maxCount){
                res=n;
                maxCount=freq[n];
            }
        }
        return res;
    }*/
};