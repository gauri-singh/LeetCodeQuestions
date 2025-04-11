class Solution {
public:
    int jump(vector<int>& nums) {
        int res=0,l=0,r=0;
        //it is like BFS and each level are group of elements that can be reached from previous level
        while(r<nums.size()-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(farthest,nums[i]+i);
            }
            l=r+1;
            r=farthest;
            res++; // increment the level
        }
        return res;
    }
};