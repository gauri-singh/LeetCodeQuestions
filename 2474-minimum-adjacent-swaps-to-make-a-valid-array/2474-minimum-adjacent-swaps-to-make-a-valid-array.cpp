class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        // find the smallest left most number and rightmost largest number if
        // there are multiple
        pair<int, int> smallest, largest;
        int n = nums.size();
        int smallI = 0, bigI = n - 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[smallI]) {
                smallI = i;
            }
            if (nums[n - i - 1] > nums[bigI]) {
                bigI = n - 1 - i;
            }
        }
        // number of min swaps is distance between 0 and small i  & bigI and n-1
        if (smallI > bigI) {
            return (smallI - 0) + (n - 1 - bigI) - 1; // subtracting 1 swap cause smallest number and biggest number will swap making it count for both
        }
        return (smallI - 0) + (n - 1 - bigI);
    }
};