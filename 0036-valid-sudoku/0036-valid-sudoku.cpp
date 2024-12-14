class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //maps of key where key is the row number and value is unordered_set for each row
        //similarly for columns
        unordered_map <int,unordered_set<char>>row,col;
        //unordered map cant have pair as its hash key without a custom operator 
        //map uses red black binary tree therefore we can use that 
        map<pair<int,int>,unordered_set<char>> square;
        char ch;
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                ch= board[r][c];
                pair<int, int> squareKey = {r/ 3,c/ 3};
                if(ch=='.') continue;
                if(row[r].count(ch)){
                    return false;
                }
                else if(col[c].count(ch)){
                    return false;
                }
                else if(square[squareKey].count(ch)){
                    return false;
                }
                row[r].insert(ch);
                col[c].insert(ch);
                square[squareKey].insert(ch);
            }
        }
        return true;
    }
};