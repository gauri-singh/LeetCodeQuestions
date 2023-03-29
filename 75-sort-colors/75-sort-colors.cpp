class Solution {
public:
    void sortColors(vector<int>& nums) {
    // int ones=0, zeroes=0,twos=0;
    //     for(int i =0;i<nums.size();i++){
    //         if(nums[i]==0) zeroes++;
    //         if(nums[i]==1) ones++;
    //         if(nums[i]==2) twos++;
    //     }
    //     nums.clear();
    //     while(zeroes){
    //         nums.push_back(0);
    //         zeroes--;
    //     }
    //     while(ones){
    //         nums.push_back(1);
    //         ones--;
    //     }
    //     while(twos){
    //         nums.push_back(2);
    //         twos--;
    //     }
        int p0,curr,p2;
        p0=0, p2= nums.size()-1;
        curr =0;
        while(curr<=p2){
            if(nums[curr]==0){
                swap(nums[curr],nums[p0]);
                curr++;
                p0++;
            }
            else if(nums[curr]==2){
                swap(nums[curr],nums[p2]);
                p2--;
            }
            else{
                curr++;
            }
        }
     }
    
};