class Solution {
public:
vector<pair<int, string>> wordMap = {
    {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"},
    {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"},
    {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"},
    {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"},
    {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"},
    {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"},
    {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"},
    {2, "Two"}, {1, "One"}
};
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }

        for(auto& [val,word] : wordMap){
            //check if the number is greater than or equal to current unit else look for smaller unit
            if(num>=val){
                // we can move forward
                //one hundred, ten thousand etc
                string prefix= (num>=100) ? numberToWords(num/val) +" ": "";
                //conver the qutotient to words if current number is greater than 100

                string unit = word ; // current unit

                string suffix = (num%val==0) ? "" :" " + numberToWords(num%val);
                return prefix+unit+suffix;
            }
        }
        return "";
    }
};