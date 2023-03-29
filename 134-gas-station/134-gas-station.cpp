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
            //solution can't exist
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
        return start;
    }
       
};
