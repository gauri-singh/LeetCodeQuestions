class Solution {
public:
    bool checkValidString(string s) {
         int leftMin=0, leftMax=0;
        for(auto ch: s){
            if(ch==')'){
                leftMin--; // decrement left
                leftMax--;
            }
            else if(ch=='('){
                leftMin++; // increment left
                leftMax++;
            }
            else{
                leftMin--; // choosing wildcard to be right character
                leftMax++;// choosing wildcard to be left character
            }

            if(leftMax<0) return false;
            if(leftMin<0) leftMin=0;
        }

    return leftMin==0;
    }
};