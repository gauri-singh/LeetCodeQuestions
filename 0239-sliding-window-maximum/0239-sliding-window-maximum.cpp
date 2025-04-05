class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0, r=0;
        deque<int> dq;// will hold the max value in the front of the deque always 
        //deque of indices
        //deque is strictly non increasing
        vector<int> res;
        while(r<nums.size()){
            while(!dq.empty() && nums[r]>nums[dq.back()]){
                //we have found a larger number we need to push to its appropriate place
                dq.pop_back();
            }
            dq.push_back(r);
            if(dq.front()<l){
                //this index is no longer in the window
                dq.pop_front();
            }
            if(r+1>=k){
                res.push_back(nums[dq.front()]);// we only start pushing to result once the window is of size k
                l++;// these conditions would be true everytime once we create the first window of size k
            }
            r++;
        }
        return res;
    }
};
