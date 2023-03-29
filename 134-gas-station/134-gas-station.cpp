class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0, totalGas = 0, minGas = INT_MAX;
        for (int i = 0; i < n; i++) {
            totalGas += gas[i] - cost[i];
            if (totalGas < minGas) {
                minGas = totalGas;
                start = i + 1;
            }
        }
        if (totalGas < 0) {
            return -1;
        }
        return start % n;
    }
};
