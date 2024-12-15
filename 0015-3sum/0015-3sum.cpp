class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int target,sum,l,r;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                //need distinct a therefore continue
                continue;
            }
            target=-nums[i];
            l=i+1, r=nums.size()-1;
            while(l<r){
                sum=nums[l]+nums[r];
                if(sum==target){
                    res.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    //new triplets
                    while(l<r && nums[l]==nums[l-1]){
                        l++; // keep moving to have next distinct nums[l]
                    }
                }
                else if(sum>target) {
                    r--; //move to decrease sum;
                }
                else{
                    l++;
                }
            }
        }
        return res;
    }
};