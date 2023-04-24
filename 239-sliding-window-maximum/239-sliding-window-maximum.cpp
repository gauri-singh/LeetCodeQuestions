class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> dq;
        // making it montonically decreasing queue
        // always decreasing as we go from left to right
        // while adding an element to DQ, if the element is greater than dq.top, then pop  until the top is not less than element , and then add the new element
        vector<int> ans;
        int left=0, right =0;
        //making a list of indices instead of value
        while(right<nums.size()){
            //pop smaller value from the deque
            while(!dq.empty() && nums[dq.back()]<nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);
            //left index is greater than the first element of the queue
            if(left>dq[0]){
                dq.pop_front();
            }
            if(1+right>=k){
                ans.push_back(nums[dq[0]]);
                left++;
            }
            right++;
        }
       
        return ans;
    }
};