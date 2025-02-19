class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> nextCandle(n, n), prevCandle(n, -1), prefixSum(n, 0); // Initialize arrays

        // Fill prevCandle and nextCandle arrays
        for (int i = 0; i < n; i++) {
            // Update prevCandle
            if (s[i] == '|') {
                prevCandle[i] = i; // It's a candle, set its position
            } else if (i > 0) {
                prevCandle[i] = prevCandle[i - 1]; // It's a plate, carry forward the previous candle
            }

            // Update nextCandle
            if (s[n - i - 1] == '|') {
                nextCandle[n - i - 1] = n - i - 1; // It's a candle, set its position
            } else if (n - i - 1 < n - 1) {
                nextCandle[n - i - 1] = nextCandle[n - i]; // It's a plate, carry forward the next candle
            }

            // Fill prefixSum array
            if (s[i] == '*') {
                prefixSum[i] = (i==0)? 1: prefixSum[i - 1] + 1; // If it's a plate, increment the sum
            } else {
                prefixSum[i] = (i==0)? 0: prefixSum[i - 1]; // If it's not a plate, carry forward the previous sum
            }
        }

        vector<int> answer;
        
        // Process queries
        for (auto& query : queries) {
            int start = nextCandle[query[0]]; // Closest candle to the right of query[0]
            int end = prevCandle[query[1]];  // Closest candle to the left of query[1]

            if (start > query[1] || end < query[0]) {
                answer.push_back(0); // No plates between the candles
            } else {
                answer.push_back(prefixSum[end] - prefixSum[start]); // Plates between the candles
            }
        }
        
        return answer;
    }
};
