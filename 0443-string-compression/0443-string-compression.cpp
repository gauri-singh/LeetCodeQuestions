class Solution {
public:
    int compress(vector<char>& chars) {
        int insertIdx=0;
        int i=0;
        while(i<chars.size()){
            char prev=chars[i];
            int groupLen=1;
            while(i+groupLen<chars.size()&& chars[i+groupLen]==prev){
                groupLen++;
            }
            chars[insertIdx]=chars[i];//at the insert position insert the character
            insertIdx++;
            if(groupLen>1){
                //if length is greater than 1 then insert the length at the insert position
                for(auto digit: to_string(groupLen)){
                    chars[insertIdx]=digit;
                    insertIdx++;
                }
            }
            i+=groupLen;
        }
        return insertIdx;//in the end insert position is the length of valid compressed string
    }
};
