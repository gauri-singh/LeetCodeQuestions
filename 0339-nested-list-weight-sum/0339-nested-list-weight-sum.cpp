/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int sum = 0, depth = 1;
        queue<NestedInteger> bfs(nestedList.begin(), nestedList.end());
        while (!bfs.empty()) {
            int size = bfs.size();
            for (int i = 0; i < size; i++) {
                NestedInteger item = bfs.front();
                bfs.pop();
                if (item.isInteger()) {
                    sum += depth * item.getInteger(); // if integer add it to the sum
                } else {
                    // if list, unpack it and push it to the queue for second round of processing
                    for (auto nested : item.getList()) {
                        bfs.push(nested);
                    }
                }
            }
            depth++;
        }
        return sum;
    }
};