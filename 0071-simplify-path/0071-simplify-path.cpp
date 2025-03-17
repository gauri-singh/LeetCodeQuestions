class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> dir;
        while(getline(ss,token,'/')){
            if(token==".."){
                if(!dir.empty())
                    dir.pop_back(); // handling going back up the parent
                continue;
            }
            else if(token=="."){
                continue;
            }
            if(token!="")
                dir.push_back(token);
        }
        string res;
        for(string curr :dir){
            if(curr.length()>0)
                res+="/"+curr;
        }
        return res.length()>0?res:"/";
    }
};