class Solution {
public:
    int findMinDistance(int index, vector<int> occurence){
        int min =9999;
        for(int i=0;i<occurence.size();i++){
            if(min> abs(occurence[i]-index)){
                min=abs(occurence[i]-index);
            }
        }
            return min;
    }
    vector<int> fillOccurenceVector(string s, char c){
        vector <int> vec;
        for(int i =0;i<s.length();i++){
            if(s[i] == c){
                vec.push_back(i);
            }
        }
            return vec;
    }
    
    vector<int> shortestToChar(string s, char c) {
        vector<int> occurence= fillOccurenceVector(s,c);
        vector<int> result;
        for(int i =0;i<s.length();i++){
            if(s[i] == c){
                result.push_back(0);
            }
            else{
                result.push_back(findMinDistance(i,occurence));
            }
        }
        return result;
    }
    
};