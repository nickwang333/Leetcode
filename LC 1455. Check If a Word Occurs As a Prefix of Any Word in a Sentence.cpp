class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int counter = 1;
        string tmp = "";
        for(int i=0; i<sentence.size(); i++){
            if(sentence[i] == ' '){
                if(searchWord.size() <= tmp.size() && tmp.substr(0, searchWord.size()) == searchWord){
                    return counter;
                }
                tmp = "";
                counter++;
            }
            else{
                tmp += sentence[i];
            }
        }
        if(searchWord.size() <= tmp.size() && tmp.substr(0, searchWord.size()) == searchWord){
            return counter;
        }
        return -1;
    }
};
