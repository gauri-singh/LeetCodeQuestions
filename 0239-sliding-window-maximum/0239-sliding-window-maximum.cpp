class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 'ans' will store the maximums for each window of size k.
        vector<int> ans;
        
        // 'dq' is a double-ended queue that will store *indices*
        // We'll maintain 'dq' so that 'nums[dq.front()]' is the maximum within the  current window.
        // Also, 'nums[dq]' is in *decreasing order* from front to back.
        deque<int> dq;
        int l = 0, r = 0;
        while (r < (int)nums.size()) {
            //    Pop from the back while 'nums[r]' is greater than 'nums[dq.back()]'
            //    so that the front always holds the largest element.
            while (!dq.empty() && nums[r] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(r);

          //If the front of the deque points to an index that is *out of this window* (i.e., < 'l'), pop it from the front. This ensures the front always corresponds to the valid range [l..r].
            if (dq.front() < l) {
                dq.pop_front();
            }
            //    We only start adding results to 'ans' once 'r+1 >= k', meaning we've processed at least k elements i.e, window size.
            if (r + 1 >= k) {
                // The front of 'dq' is the index of the window's maximum.
                ans.push_back(nums[dq.front()]);
                // Move the left pointer to shrink the window from the left
                l++;
            }
            r++;
        }
        
        return ans;
    }
};
