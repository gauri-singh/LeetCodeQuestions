class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map <int,int> map;
        int sum=0,longestSub=0,currSub;
        //if number is 1, we add +1
        //if number is 0 we subtract -1
        //if any time sum =0 , it means perfectly balanced 0s and 1s at this point
        //if any sum number repeats, this means all the elements between these two points have a sum of equal to 0, means have balanced 1s and zeores between them 
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]==1?1:-1;
            if(sum==0){
                //sum from 0 to i
                longestSub=max(longestSub,i+1);
                continue;
            }
            if(map.find(sum)!=map.end()){
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