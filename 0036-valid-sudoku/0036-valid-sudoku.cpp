class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>>row,col;
        map<pair<int,int>,unordered_set<char>> subgrid;
        char ch;
        for(int r=0;r<9;r++){
           for(int c=0;c<9;c++) {
               ch=board[r][c];
               if(ch=='.'){
                   continue;
               }
               if(row[r].count(ch)){
                   return false;
               }
                if(col[c].count(ch)){
                   return false;
               }
               pair<int,int> subgridKey=make_pair(r/3,c/3);
                if(subgrid[subgridKey].count(ch)){
                   return false;
               }
               row[r].insert(ch);
               col[c].insert(ch);
               subgrid[subgridKey].insert(ch); 
           }
        }
        return true;
    }
};