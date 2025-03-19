class Solution {
public:
//optimal greedy
    int maximumSwap(int num) {
        string str=to_string(num);
        int n=str.length();
        int maxIndex=-1;
        int swapIndex1=-1, swapIndex2=-1;
        //storing the index with max value to the right of the current character
        for(int i=n-1;i>=0;i--){
            if(maxIndex==-1 || str[i]>str[maxIndex]){
                maxIndex=i;
            }else if(str[i]< str[maxIndex]){
                //current index is smaller than max index and can be used for swapping later
                //since we need the smaller number to be as close to the start as possible we can just keep repeating it so we find the last from right, smallest number which can be swapped.
              swapIndex1=i;
              swapIndex2=maxIndex;
            }
        }
        if(swapIndex2!=-1 && swapIndex1!=-1){
            swap(str[swapIndex2],str[swapIndex1]);
        }
      return stoi(str);
    }
};
//2 pass greedy
// class Solution {
// public:
//     int maximumSwap(int num) {
//         string str=to_string(num);
//         int n=str.length();
//         vector<char>maxRight(n,'0');
//         maxRight[n-1]=n-1;
//         //storing the index with max value to the right of the current character
//         for(int i=n-2;i>=0;i--){
//             if(str[i]>str[maxRight[i+1]]){
//                 maxRight[i]=i;
//             }else{
//                 maxRight[i]=maxRight[i+1];
//             }
//         }
//         for(int i=0;i<n;i++){
//             if(str[i]<str[maxRight[i]]){
//                 swap(str[i],str[maxRight[i]]);
//                 return stoi(str);
//             }
//         }
//       return stoi(str);
//     }
// };