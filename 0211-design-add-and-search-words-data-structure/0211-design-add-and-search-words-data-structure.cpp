class TrieNode{
    public:
    unordered_map<char,TrieNode*> children;
    bool isEnd=false;
};
class WordDictionary {
public:
TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(auto ch: word){
            if(!curr->children.count(ch)){
                curr->children[ch]= new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        return dfs(0,word,root);
    }
    bool dfs(int index,string word, TrieNode* node){
        TrieNode* curr = node;
        for(int i=index;i<word.size();i++){
            char ch=word[i];
            if(ch=='.'){
                for(auto& [key,child] : curr->children){
                    //in the children map of current node search recursively if any path leads to end of word
                    if(child && dfs(i+1,word,child)){
                        //if recursively any path was found then return true;
                        return true;
                    }
                }
                    //no path was found so return false
                    return false;
            }
            else{
                if(!curr->children.count(ch)){
                    return false;
                    // this character is not in the children of previous node so word is not in prefix treee
                }
                curr = curr->children[ch];
            }
        }
        //check if the last character of this word in tree is end of word or not
        return curr->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */