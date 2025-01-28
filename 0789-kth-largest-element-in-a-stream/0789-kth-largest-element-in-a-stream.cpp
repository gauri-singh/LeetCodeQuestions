class KthLargest {
public:
priority_queue<int,vector<int>,greater<int>> minheap;
int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto num: nums){
            minheap.push(num);
            if(minheap.size()>k){
                minheap.pop(); // pop smaller numbers;
            }
        }
    }
    
    int add(int val) {
        minheap.push(val);
            if(minheap.size()>k){
                minheap.pop(); // pop k+1st largest numbers;
            }

        return minheap.top(); // kth largest number
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */