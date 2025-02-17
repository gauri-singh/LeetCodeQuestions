class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end() || 
            beginWord == endWord){
            //end word is not in the word list or both words are same no need to climb the ladder
            return 0;
        }
        unordered_map<string,vector<string>> adj;
        wordList.push_back(beginWord);
        // dot will be in the adj list for d*t,*ot,do* 
        //*ot = dot,hot,cot,rot etc 
        for(auto word: wordList){
            for(int i=0;i<word.length();i++){
                string pattern=word.substr(0,i)+"*"+word.substr(i+1);
                adj[pattern].push_back(word);
            }
        }
        queue<string> q;
        unordered_set<string> visited;
        visited.insert(beginWord);
        q.push(beginWord);
        int res=1;
        while(!q.empty()){
            int len =q.size();
            for(int i=0;i<len;i++){
                string word = q.front();
                q.pop();
                if(word==endWord){
                    return res;
                }
                //find each pattern where the current word falls into and then go to each of the neighbors 
                for(int i=0;i<word.length();i++){
                    string pattern=word.substr(0,i)+"*"+word.substr(i+1);
                   for(auto neighbor : adj[pattern]){
                    if(!visited.count(neighbor)){
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }  
                   }
                }
            }
            res++; //increase length at each layer
        }

        return 0;// no path found
    }
};