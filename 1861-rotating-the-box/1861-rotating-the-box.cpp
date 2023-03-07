class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n= box.size();
        int m=box[0].size();
        vector<vector<char>> result(m,vector<char>(n));
        //we have to shift everything to the right and then rotate the box ,i.e, create a new box and swap i j values
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                if(box[i][j]=='#'){
                    int empty = j+1;
                    while(empty<m && box[i][empty]=='.'){
                        empty++;
                        //finding the last empty space to swap
                    }
                    if(empty<m && box[i][empty]=='.'){
                        //obstacle encountered, didnt reach out of the box
                        box[i][empty]='#';
                        box[i][j]='.';
                    }
                    else if(empty-1<m  && box[i][empty-1]=='.'){
                        box[i][empty-1]='#';
                        box[i][j]='.';
                    }
                }
            }
        }
        int k=n-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result[j][k]=box[i][j];
            }
            k--;
        }
        return result;
    }
};

