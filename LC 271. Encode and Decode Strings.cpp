class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ret;
        char non_ascii = '0' + 130;
        for(string i:strs){
            ret += i;
            ret += non_ascii;
        }
        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ret;
        string tmp;
        for(char i:s){
            if(i-' '<0){
                ret.push_back(tmp);
                tmp = "";
            }
            else{
                tmp += i;
            }
        }
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
