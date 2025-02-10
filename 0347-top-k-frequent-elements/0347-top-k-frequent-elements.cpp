class Solution {
public:
    //using heap:
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map <int,int> freqTab;
    //     for(auto it:nums){
    //         freqTab[it]++;
    //     }
    //     priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
    //     for(auto it:freqTab){
    //        minheap.push({it.second,it.first});//pq uses first element in pair to calculate priority, therefore switching here to make the frequency appear first in the pushed pair
    //         if(minheap.size()>k){
    //             minheap.pop();
    //         }
    //     }
    //      vector<int> res;
    //     while(minheap.size()){
    //         res.push_back(minheap.top().second);
    //         minheap.pop();
    //     }
    //     return res;
    // }
    //Using bucketsort
       vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
         pair<int,int> p ;
        for(auto it:nums){
            map[it]++;
        }
       vector<vector<int>> counts(nums.size()+1); //since we wont use 0 but we will use n+1 see notes 
       //frequency x vector of numbers with that frequency
       for(auto it:map){
           //it.first - num and it.second is frequency
           counts[it.second].push_back(it.first);
           
       }
        vector<int> res;
       for(int i=counts.size()-1;i>=0;i--){
           //reversing would start with max frequency;
           res.insert(res.end(),counts[i].begin(),counts[i].end()); // append the number with ith frequency to the result vec
           if(res.size()==k){
               return res;
           }
       }
           
        return res;
    }
};