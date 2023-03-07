class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char,int> table={{'I' ,1},{'V' ,5},{'X' ,10},{'L' ,50},{'C' ,100},{'D' ,500},{'M' ,1000}};
        int num = 0;
        for (int i = 0; i < s.length() - 1; ++i) {
            if (table[s[i]] < table[s[i + 1]]) {
                // in case of 4 or 9 we do this as num-1+5 = num +4 etc
                num -= table[s[i]];
            } else {
                //since roman numbers are in descending order for other cases, we just add the values
                num += table[s[i]];
            }
        }
        num += table[s.back()];
        return num;
            
        }
    
};