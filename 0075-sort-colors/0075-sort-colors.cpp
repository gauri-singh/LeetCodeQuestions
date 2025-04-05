class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        int curr=0;
       while(curr<=right){
            if(nums[curr]==0){
                swap(nums[curr],nums[left]);
                left++;
            }
            else if(nums[curr]==2){
                swap(nums[curr],nums[right]);
                right--;
                continue;
            }
            curr++;
       } 
        
    }
};