class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(),start=0,sumGas=0,sumCost=0,total=0;
        vector<int> diff(n,0);
        for(int i=0;i<n;i++){
            diff[i]=gas[i]-cost[i];
            sumGas+=gas[i];
            sumCost+=cost[i];
        }
        if(sumGas<sumCost){
            //solution can't exist since total gas< total cost
            return -1;
        }
        //solution must exist
        for(int i=0;i<n;i++){
            
            total+=diff[i];
            if(total<0){
                //find new start position because this one has failed.
                total =0;
                start=i+1;
            }
        }
        // we don't go in a loop because we know a solution exists and that if we found one element in diff array where gas-cost>0 and its not reset till end of the array it means that is the answer  
        return start;
    }
       
};
