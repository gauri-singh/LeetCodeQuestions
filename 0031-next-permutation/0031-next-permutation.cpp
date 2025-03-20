class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // longest prefix match is necessary : see striver video
        // go from right to left,find the first number where the ith value> i-1- > the i-1 is our pivot, we want largest prefix match thats why we go from r to l
        int pivot =-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                //pivot is at i-1;
                pivot=i-1;
                break; 
            }
        }
        if(pivot==-1){
            //it is the last permutation
            reverse(nums.begin(),nums.end());
            return;
        }
        // another thing to notice is that the second half of the array is sorted in descending order so
        // again going from right, we find the first number which is larger than our pivot (this will be the smallest number>pivot)and place it at the pivot-> so we find the very next permutation
        for(int i=nums.size()-1;i>pivot;i--){
            if((nums[i]>nums[pivot])){
                swap(nums[pivot],nums[i]);
                break;
            }
        }
         //from pivot till the end, we need to modify the values such that the array is in a sorted order
         cout<<pivot;
        reverse(nums.begin()+pivot+1,nums.end());
    }
};