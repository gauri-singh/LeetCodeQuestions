class NumMatrix {
public:
int ROWS,COLS;
vector<vector<int>> prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        ROWS=matrix.size();
        COLS=matrix[0].size();
        prefixSum.resize(ROWS + 1, vector<int>(COLS + 1, 0));
        for(int i=0;i<ROWS;i++){
            int prefix=0;
            for(int j=0;j<COLS;j++){
                prefix+=matrix[i][j];
                int above= prefixSum[i][j+1]; // using 1 to offset the extra 0s col and row
                prefixSum[i+1][j+1]= prefix+above;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
            return prefixSum[row2 + 1][col2 + 1]
             - prefixSum[row1][col2 + 1]
             - prefixSum[row2 + 1][col1]
             + prefixSum[row1][col1];
        // row1++,col1++,row2++,col2++; // to offset for 1s
        // int bottomRight= prefixSum[row2][col2];
        // int above=prefixSum[row1-1][col2];
        // int left=prefixSum[row2][col1-1];
        // int topLeft=prefixSum[row1-1][col1-1];
        // return bottomRight-above-left+topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */