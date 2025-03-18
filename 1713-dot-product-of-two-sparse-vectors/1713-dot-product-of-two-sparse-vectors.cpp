//Tuple solution
class SparseVector {
public:
vector<pair<int,int>> tuples;
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                tuples.push_back({i,nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum=0;
        int i=0,j=0; // i is for first vector j is for second vector
        while(i<tuples.size() && j<vec.tuples.size()){
            if(tuples[i].first==vec.tuples[j].first){
                //if the indices match
                sum+=tuples[i].second*vec.tuples[j].second;
                i++;j++;
            }else{
                //indices dont match
                if(tuples[i].first<vec.tuples[j].first){
                    i++;
                }
                else{
                    j++;
                }
                //move the pointer with smaller index
            }
        }
        return sum;
    }
};
//Hashtable solution
// class SparseVector {
// public:
//  unordered_map<int,int> map;
//     SparseVector(vector<int> &nums) {
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]!=0){
//                 map[i]=nums[i];
//             }
//         }
//     }
    
//     // Return the dotProduct of two sparse vectors
//     int dotProduct(SparseVector& vec) {
//         int sum=0;
//         for(auto&[index,val] : this->map){
//             if(vec.map.count(index)){
//                 sum+=val*vec.map[index];
//             }
            
//         }
//         return sum;
//     }
// };

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);