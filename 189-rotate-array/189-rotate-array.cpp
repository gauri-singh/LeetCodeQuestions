class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        //reversing the whole array
        for(int i=0,j=nums.size()-1;i<j;i++,j--){
            swap(nums[i],nums[j]);
        }
        // reversing the first sub array from i=0 to i=k-1
        for(int i=0,j=k-1;i<j;i++,j--){
            swap(nums[i],nums[j]);
        }
        //reversing second subarray from  i=k to end of array 
        for(int i=k,j=nums.size()-1;i<j;i++,j--){
            swap(nums[i],nums[j]);
        }
    }
};