class TrieNode{
    public:
    unordered_map<char,TrieNode*> children;
    bool isEndOfWord=false;
};
class Trie {
public:
TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char ch: word){
            if(!curr->children.count(ch)){
                //if not in map add as a new child node
                curr->children[ch]=new TrieNode();
            }
            curr = curr->children[ch];
        }
        //curr would be now the last character so mark as end of word;
        curr->isEndOfWord= true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char ch: word){
            if(!curr->children.count(ch)){
                //if not in map  return false
                return false;
            }
            curr = curr->children[ch];
        }
        //we need exact match so if the the last character of the word is not endofword then it means it is not inserted in trie and is just a prefix of another word in trie.
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
         TrieNode* curr = root;
        for(char ch: prefix){
            if(!curr->children.count(ch)){
                //if not in map  return false
                return false;
            }
            curr = curr->children[ch];
        }
        //we don't need exact match so even being a prefix works
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */