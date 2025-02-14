class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0,startIndex=0;
        if(accumulate(gas.begin(),gas.end(),0)-accumulate(cost.begin(),cost.end(),0)<0){
            return -1; // solution doesnt exist
        }
        //solution must exist
        for(int i=0;i<gas.size();i++){
            total+=gas[i]-cost[i];
            if(total<0){
                total=0;
                startIndex=i+1; // moving start index to next value, because we cant start from previous place since total was negative
            }
        }
        return startIndex;
    }
};