class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded;
        for(auto word: strs){
            encoded+=to_string(word.length())+'#'+word;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        for(int i=0;i<s.length();i++){
            //find length of the string
            string digit="";
            while(isdigit(s[i])){
                //start of new word- find length
                digit+=s[i];
                i++;
            }
            int len=stoi(digit);
            res.push_back(s.substr(i+1,len));
            i=i+len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));