//more cleaner same logic
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
        int i=0,j=0;// i is the pointer for first list, j is the pointer for second list
        vector<vector<int>> res;
        while(i<first.size() && j<second.size()){
            int low= max(first[i][0],second[j][0]);
            int high= min(first[i][1],second[j][1]);
            if(low<=high){
                //there is overlap
               res.push_back({low,high});
            }  
            //we move the pointer of the interval that ends first
            if(first[i][1]<second[j][1]){
                i++;
            }else{
                j++;
            }
            
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
//         int i=0,j=0;// i is the pointer for first list, j is the pointer for second list
//         vector<vector<int>> res;
//         while(i<first.size() && j<second.size()){
//             if(!(first[i][1]<second[j][0] || second[j][1]<first[i][0])){
//                 //there is overlap -> easier to negate no overlap case haha
//                res.push_back({max(first[i][0],second[j][0]),min(first[i][1],second[j][1])});
//             }  
//             //we move the pointer of the interval that ends first
//             if(first[i][1]<second[j][1]){
//                 i++;
//             }else{
//                 j++;
//             }
            
//         }
//         return res;
//     }
// };