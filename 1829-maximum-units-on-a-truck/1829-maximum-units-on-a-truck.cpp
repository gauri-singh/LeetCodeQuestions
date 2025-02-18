class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int,int>> maxheap;
        for(auto box: boxTypes){
            // we need to sort by max units therefore
            maxheap.push({box[1],box[0]});
        }
        int res=0,totalBox=0;
        while(!maxheap.empty()&& totalBox<=truckSize ){
            int units=maxheap.top().first;
            int boxes=maxheap.top().second;
            maxheap.pop();
            res+=units*min(truckSize-totalBox,boxes);
            totalBox+=min(truckSize-totalBox,boxes);
        }
        return res;
    }
};