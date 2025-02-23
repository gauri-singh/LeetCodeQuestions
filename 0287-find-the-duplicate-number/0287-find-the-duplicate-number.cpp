class Solution {
public:
    // int findDuplicate(vector<int>& nums) {
    //     //nums is an array of indexes
    //     int fast=0,slow=0;
    //     //Phase 1 : find the intersection ,i.e, cycle, 
    //     while (true){
    //         slow=nums[slow]; // essentially like slow= slow->next 
    //         fast= nums[nums[fast]]; // fast= fast->next->next;
    //         if(slow==fast)
    //             break;
    //     }
    //     int slow2=0;
    //     //phase 2: find entrance to the intersection
    //     //according to floyd, if you keep a pointer at the intersection,  and then keep a pointer at the start of the list, and move both the pointers at the same speed, they will collide at the entry of the intersection

    //     while(true){
    //         slow=nums[slow]; 
    //         slow2=nums[slow2];
    //         if(slow==slow2){
    //             return slow; // or slow2
    //         }
    //     }
    // }
    // Aman's method
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int pos=abs(nums[i]);
            if(nums[pos]<0){
                return abs(nums[i]);
            }
            nums[pos]=-nums[pos];
        }
        return -1;
    }

};