class Solution {
public:
//preferred way:
    int maximumSwap(int num) {
        string str= to_string(num);
        int maxIndex=-1, swapIndex1=-1, swapIndex2=-1;
        for(int i=str.length()-1;i>=0;i--){
            if(maxIndex==-1 || str[i]>str[maxIndex]){
                maxIndex=i;
            }else if(str[i]<str[maxIndex]){
                //can't do just else otherwise will get error for repeated max digits
                swapIndex1=maxIndex;
                swapIndex2=i;
            }
        }
        if(swapIndex1!=-1 && swapIndex2!=-1){
            swap(str[swapIndex1],str[swapIndex2]);
            return stoi(str);
        }
        return num;
    }
/*minmer's technique
    int maximumSwap(int num) {
        string str= to_string(num);
        vector<int> rightMostIndex(10,-1);
        for(int i=0;i<str.length();i++){
            int n= str[i]-'0';
            rightMostIndex[n]=i;
        }
        for(int i=0;i<str.length();i++){
            int currNum=str[i]-'0';
            for(int j=9;j>currNum;j--){
                if(rightMostIndex[j]>i){
                    swap(str[i],str[rightMostIndex[j]]);// swap current number with index stored in the vector
                    return stoi(str);
                }
            }
        }
        return num;
    }*/
};