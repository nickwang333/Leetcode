class Solution {
public:
    string compressedString(string word) {
        string ret = "";
        int counter = 1, n = word.size();
        char c = word[0];
        for(int i=1; i<n; i++){
            if(word[i] == word[i-1]){
                if(counter == 9){
                    ret += to_string(counter);
                    ret += c;
                    counter = 1;
                    c = word[i];
                }
                else{
                    counter++;
                }
            }
            else{
                ret += to_string(counter);
                ret += c;
                counter = 1;
                c = word[i];
            }
        }
        ret += to_string(counter);
        ret += c;
        return ret;
    }
};
