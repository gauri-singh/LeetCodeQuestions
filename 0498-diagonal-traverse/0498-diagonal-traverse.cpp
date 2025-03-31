class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.empty()){
            return {};
        }
        int n=mat.size(), m=mat[0].size();
        //sum of i+j = index of diagonal
        vector<int> res;
        //diag goes from n-1+ m-1=> (n+m-2)
        for(int diag=0;diag<=n+m-2;diag++){
            for(int x=0;x<=diag;x++){
                int i=x;
                int j=diag-i; //since i+j=diag
                if(diag%2==0){
                    //even diagonal we are going in opposite direction
                    swap(i,j);
                }
                if(i>=n || j>=m) continue;
                res.push_back(mat[i][j]);
            }
        }
        return res;
    }
};