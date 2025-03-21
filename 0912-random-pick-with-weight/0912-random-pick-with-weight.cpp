class Solution {
public:
int total=0;
vector<int> prefixSum;
    Solution(vector<int>& w) {
        // probability of getting a number based on its weight so total probability = sum of all numbers
        // for each number we have buckets based on their weight eg 
        //[1,2,3] = 1/6,2/6,3/6 => (0,1] , (1,3], (3,6] ||| (- exclusive ]- inclusive
        // where each bucket represents chance of being selected, 1 has bucket of size 1, 2 has 2x of 1 i.e,size 2, and 3 has bucket of size 3.
        prefixSum=vector<int> (w.size());
        partial_sum(w.begin(),w.end(),prefixSum.begin());
        total=prefixSum.back(); // last element will have the total value
    }
    
    int pickIndex() {
        int target = rand() % total; // this will generate random number from 0-target
        // and whatever number comes, we can find which chunk it will belong to
        int l=0, r=prefixSum.size()-1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (prefixSum[mid] > target) { 
                r = mid;
            } else {
                l = mid + 1;
            }
        }
         return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */