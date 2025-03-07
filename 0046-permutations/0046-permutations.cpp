class Solution {
public:
// better way:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(curr,ans,nums);
        return ans;
    }
    void backtrack(vector<int>& curr, vector<vector<int>>& ans, vector<int> nums){
        //base case
        if(curr.size()==nums.size()){
            //we have found one permutation
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(find(curr.begin(),curr.end(),nums[i])==curr.end()){
                //the current number is not in ther permutation, so we can add and check if it completes
                curr.push_back(nums[i]);
                backtrack(curr,ans,nums);
                curr.pop_back();
            }
        }
    }
// //recursion
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> res;
//         if(nums.empty()){
//             //since we are popping one element at a time
//             return {{}};
//         }
//         //remove first element from nums and call permute function recursively so we cn get every permutation of all elements except first one
//         //then add first one at every possible position in each of these permutations;
//         vector<int> temp(nums.begin()+1,nums.end()); //pop nums[0]
//         vector<vector<int>> perms= permute(temp);

//         for(auto p: perms){
//             //each p is a permutation vector
//             for(int i=0;i<=p.size();i++){
//                 //<= p size so we can insert in end of current vector also
//                 vector<int> p_copy=p;
//                 p_copy.insert(p_copy.begin()+i,nums[0]); //insert the first element at every ith index
//                 res.push_back(p_copy);// push this new permutation in result;
//             }
//         }
//         return res;
//     }
// //iteration
//     // vector<vector<int>> permute(vector<int>& nums) {
//     //     vector<vector<int>> perms={{}};

//     //     for(auto n: nums){
//     //         //for each number we want to add it to existing permutation
//     //         vector<vector<int>> new_perms;
//     //         for(auto p: perms){
//     //             // p is each individual permutation vector
//     //             //insert the number n in each of the possible places in p
//     //             for(int i=0;i<=p.size();i++){
//     //                 //<= to size cause we also want to insert at the end of the current permutation
//     //                 vector<int> p_copy=p;
//     //                 p_copy.insert(p_copy.begin()+i,n);
//     //                 new_perms.push_back(p_copy);
//     //             }
//     //         }
//     //         perms=new_perms;
//     //     }
//     //     return perms;
//     // }

};