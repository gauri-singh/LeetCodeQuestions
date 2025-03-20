
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        // Edge case: Start or end blocked
        if (grid[0][0] != 0 || grid[ROWS-1][COLS-1] != 0) return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;  // Marking visited by changing value

        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},{0, 1}, {1, -1}, {1, 0}, {1, 1}};

        int pathLen = 0;  // Start position is counted as the first step

        while (!q.empty()) {
            int size = q.size();
            pathLen++;
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                // Check if reached the bottom-right cell
                if (r == ROWS - 1 && c == COLS - 1) {
                    return pathLen; // since we are going in bfs order, we will return shortest distance first only
                }
                // Explore all 8 directions
                for (auto [dr, dc] : directions) {
                    int currR = r + dr, currC = c + dc;
                    if (currR >= 0 && currR < ROWS && currC >= 0 && currC < COLS && grid[currR][currC] == 0) {
                        q.push({currR, currC});
                        grid[currR][currC] = 1; // Mark as visited
                    }
                }
            }
        }
        return -1;
    }
};