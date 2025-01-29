class Solution {
public:
//with heap
    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int,vector<int>,greater<int>> minheap;
    //     //if we maintain a minheap of size k, the element on top would be the kth largest element, 
    //     //cause smaller elements would be popped.
    //     for(auto num:nums){
    //         minheap.push(num);
    //         if(minheap.size()>k){
    //             minheap.pop(); //popping k+1 largest elements;
    //         }
    //     }
    //     return minheap.top();
    // }
    //with quickselect
    int findKthLargest(vector<int>& nums, int k) {
        k=nums.size()-k;
       return quickSelect(0,nums.size()-1,nums,k);
    }
    int quickSelect(int l,int r, vector<int>& nums,int k){
        int pivot=nums[r]; // choose a random pivot
        int p=l; // pointer for where to start partition and move it
        for(int i=l;i<r;i++){
            if(nums[i]<pivot){
                swap(nums[i],nums[p]);
                p++;
            }
        }
        //swap the pivot cause the partition was created based on it
        swap(nums[p],nums[r]);
        if(p>k){
            //parition has moved forward from point of interest
            return quickSelect(l,p-1,nums,k);// move it to left parition and check again
        }
        else if(p<k){
            //parition needs to moved forward to get to point of interest
            return quickSelect(p+1,r,nums,k);// move it to right parition and check again
        }
        else{
            return nums[p]; // or nums[k]
        }
    }

};