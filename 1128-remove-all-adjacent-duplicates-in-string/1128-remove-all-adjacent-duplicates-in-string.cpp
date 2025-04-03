class Solution {
public:
    string removeDuplicates(string s) {
        //using stack as a vector for easy string conversion
       vector<int> stackVec;
       for(auto ch: s){
            if(!stackVec.empty() && stackVec.back()==ch){
               stackVec.pop_back();
            }else{
                stackVec.push_back(ch);
            }
       }
       return string(stackVec.begin(),stackVec.end());
    }
};