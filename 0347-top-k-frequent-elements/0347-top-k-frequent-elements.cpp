class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> freqTab;
        for(auto it:nums){
            freqTab[it]++;
        }
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
        for(auto it:freqTab){
           minheap.push({it.second,it.first});//pq uses first element in pair to calculate priority, therefore switching here to make the frequency appear first in the pushed pair
            if(minheap.size()>k){
                minheap.pop();
            }
        }
         vector<int> res;
        while(minheap.size()){
            res.push_back(minheap.top().second);
            minheap.pop();
        }
        return res;
    }
};