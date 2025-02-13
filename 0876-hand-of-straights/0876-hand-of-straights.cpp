class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> freq;
        priority_queue<int,vector<int>,greater<int>> minheap;
        for(auto val:hand){
            freq[val]++; // frequency map of each card value
            if(freq[val]==1){
                minheap.push(val); 
            }
        }
        while(!minheap.empty()){
            int first=minheap.top();//first of this group
            for(int i=first;i<first+groupSize;i++){
                if(!freq.count(i)){
                    //the value needed is not present 
                    return false;
                }
                freq[i]--;
                if(freq[i]==0){
                    if(minheap.top()!=i){
                        return false;
                    }
                    minheap.pop();
                }
            }
        }
        return true;
    }
};