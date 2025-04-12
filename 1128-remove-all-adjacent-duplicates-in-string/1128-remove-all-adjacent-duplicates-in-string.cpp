class Solution {
public:
    string removeDuplicates(string s) {
       string result;// we could use a vector but that would just be extra space
       for(auto ch: s){
            if(!result.empty() && result.back()==ch){
               result.pop_back();
            }else{
                result+=ch;
            }
       }
       return result;
    }
};