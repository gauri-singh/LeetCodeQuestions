class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> maxheap;
        for(auto stone: stones){
            maxheap.push(stone);
        }
        while(maxheap.size()>1){
            int x = maxheap.top();
            maxheap.pop();
            int y = maxheap.top();
            maxheap.pop();

            maxheap.push(abs(x-y));
        }
        return maxheap.top();
    }
};