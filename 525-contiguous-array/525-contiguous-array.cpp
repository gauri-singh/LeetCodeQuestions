class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map <int,int> map;
        unordered_map <int,int> :: iterator it;
        int sum=0,longestSub=0,currSub;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]==1?1:-1;
            if(sum==0){
                //include all the 
                longestSub=max(longestSub,i+1);
                continue;
            }
            it=map.find(sum);
            if(it!=map.end()){
                currSub=i-map[sum];
                longestSub=max(longestSub,currSub);
            }
            else{
                map[sum]=i;
            }
            
        }
        return longestSub;
    }
};