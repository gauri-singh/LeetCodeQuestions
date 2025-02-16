class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> unique;
        for(auto n: nums){
            if(n!=0){
                unique.insert(n);
            }
        }
        return unique.size();
    }
};