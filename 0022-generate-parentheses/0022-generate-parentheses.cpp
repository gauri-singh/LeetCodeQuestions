class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string stack="";
        backtrack(0,0,n,result,stack);
        return result;
    }
    void backtrack(int openN,int closeN, int n, vector<string> &result, string stack){
        if(openN==closeN && openN==n){
            //base case is met, all matching opening and closing braces + n has been met
            result.push_back(stack);
            return;
        }
        if(openN<n){
            //add more opening braces
            stack+='(';
            backtrack(openN+1,closeN,n,result,stack);
            stack.pop_back();
        }
        if(closeN<openN){
            //add more closing braces
            stack+=')';
            backtrack(openN,closeN+1,n,result,stack);
            stack.pop_back();
        }
    }
};