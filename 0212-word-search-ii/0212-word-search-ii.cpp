class TrieNode{
    public:
    unordered_map<char,TrieNode*> children;
    bool isEnd=false;
};
class Solution {
public:
unordered_set<string> result;
TrieNode* root;
int ROWS,COLS;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root= new TrieNode;
        for(auto word: words){
            insertToTrie(word);
        }
        ROWS=board.size(); COLS=board[0].size();
        string curr="";
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                dfs(i,j,board,curr,root);
            }
        }
        return vector<string>(result.begin(),result.end());
    }
    void dfs(int r,int c,vector<vector<char>>& board,string& currWord, TrieNode* curr){
        if(r<0 || r>=ROWS ||c<0 || c>=COLS || board[r][c] == '#' || !curr->children.count(board[r][c])){
            return;
        }
        char ch=board[r][c];
        board[r][c] = '#';
        curr=curr->children[ch];
        currWord+=ch;
        if(curr->isEnd){
            curr->isEnd=false; // to not find this word again
            result.insert(currWord);
        }
        

        dfs(r-1,c,board,currWord,curr);
        dfs(r+1,c,board,currWord,curr);
        dfs(r,c-1,board,currWord,curr);
        dfs(r,c+1,board,currWord,curr);
        board[r][c] = ch;
        currWord.pop_back();

        
    }

    void insertToTrie(string word) {
        TrieNode* curr=root;
        for(auto ch: word){
            if(!curr->children.count(ch)){
                curr->children[ch]=new TrieNode();
            }
            curr=curr->children[ch];
        }
        curr->isEnd=true;
    }
};