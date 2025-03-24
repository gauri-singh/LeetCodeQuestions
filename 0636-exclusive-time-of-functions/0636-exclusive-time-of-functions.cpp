class Solution {
public:
stack<int> st;
int prevTime=0;

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> soloTime(n,0);
        for(auto log: logs){
            helper(log,soloTime);
        }
        return soloTime;
    }
    void helper(string log,vector<int>& soloTime){
        string token;
        vector<string> tokens;
        stringstream ss(log);
        while(getline(ss,token,':')){
            tokens.push_back(token);
        }
        int id= stoi(tokens[0]);
        int timeStamp=stoi(tokens[2]);
        if(tokens[1]=="start"){
            //on start add the time the function ran
            if(!st.empty()){
                soloTime[st.top()]+=timeStamp-prevTime;
            }
            st.push(id);
            prevTime=timeStamp;
        }else{
            //on end, add the time the function ran+1
            //cam be soloTime[id] as well, cause its single threaded
            soloTime[st.top()]+=timeStamp-prevTime+1; // because inclusive
            st.pop();
            prevTime=timeStamp+1;
        }
    }
};