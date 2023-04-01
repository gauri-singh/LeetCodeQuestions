class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set <int> set;
        for(auto it: nums){
            set.insert(it);
        }
        
        int currStreak=0, maxStreak=0,currNum;
        for(auto num:nums){
            if(!set.count(num-1)){
                //this number is the first number of the subsequence
                //its predecessor doesnt exist
                currStreak =0;
                currNum=num;
                 while(set.count(currNum)){
                currStreak++;
                currNum++;
            }
            }
           
            maxStreak = max(maxStreak,currStreak);
        }
        return maxStreak;
    }
};