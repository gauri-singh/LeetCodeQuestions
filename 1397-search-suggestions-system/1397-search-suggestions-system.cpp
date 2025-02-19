class TrieNode{
    public:
    unordered_map<char,TrieNode*> children;
    bool end=false;
};
class Solution {
public:
TrieNode* root;
vector<vector<string>>  res;
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root=new TrieNode();
        for(auto word: products){
            insertWord(word);
        }
        for(int i=0;i<searchWord.size();i++){
            res.push_back(search(searchWord.substr(0,i+1)));
        }
        return res;
    }
    vector<string> search(string prefix){
        TrieNode* curr = root;
        vector<string> suggestions;
            for(auto ch: prefix){
                if(!curr->children.count(ch)){
                    return suggestions;
                }
                curr=curr->children[ch];
            }
            //end node of the last word, now we have the prefix, now we will do dfs to find words starting with this prefix;
            dfs(curr,prefix,suggestions);
            return suggestions;
       
    }
    void dfs(TrieNode* curr, string prefix, vector<string>& suggestions){
        if(suggestions.size()==3){
            return ;
        }
        if(curr->end){
            //this is end of word, we can add this to suggestion
            suggestions.push_back(prefix);
        }
        //going in sequence guarantees lexicographic
        for(char ch='a';ch<='z';ch++){
            if(curr->children.count(ch)){
                 dfs(curr->children[ch],prefix+ch,suggestions);
            }
        }
    }

    void insertWord(string word){
        TrieNode* curr = root;
        for(auto ch: word){
            if(!curr->children.count(ch)){
                curr->children[ch]=new TrieNode();
            }
            curr=curr->children[ch];
        }
        curr->end=true;
    }
};