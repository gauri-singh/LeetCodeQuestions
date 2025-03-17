class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> dir;
        // instead of vector we can do it with a stack also same logic literally just datastrcture change
        while(getline(ss,token,'/')){
            if(token==".."){
                if(!dir.empty())
                    dir.pop_back(); // handling going back up the parent
                continue;
            }
            else if(token=="."){
                continue; // current directory skip
            }
            if(token!="")
                dir.push_back(token);// empty directories skip
        }
        string res;
        for(string curr :dir){
                res+="/"+curr;
        }
        return res.length()>0?res:"/";
    }
};