class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // since majority element is n/3, at most we can have only 2 elements that can be majority element
        // maintain a hashmap of size 2, if ever there are 3 elements, decrement the count of every number and remove the elemnt with count 0, if all elements are removed, no worries, majority would repopulate again ( neetcode way, this is similar but without hashmap which helps for 2nd pass)
        int count1 = 0, count2 = 0;
        int candidate1 = 0, candidate2 = 1;
        // 1st pass: Find potential candidates
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // 2nd pass: Validate actual counts
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        vector<int> res;
        int n = nums.size();
        if (count1 > n / 3) res.push_back(candidate1);
        if (count2 > n / 3) res.push_back(candidate2);
        return res;
    }
};
