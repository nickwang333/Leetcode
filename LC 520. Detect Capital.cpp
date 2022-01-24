class Solution {
public:
    bool detectCapitalUse(string word) {
        int flag = 0;
        if(word.size()==1){
            return true;
        }
        for(int i=0; i<word.size(); i++){
            if(i==0 && ((word[i]-'A' >= 0) && (word[i]-'A' < 26))){
                if((word[1]-'A' >= 0) && (word[1]-'A' < 26)){
                    flag = 1;
                }
            }
            else{
                if(flag == 0){
                    if((word[i]-'A' >= 0) && (word[i]-'A' < 26)){
                        return false;
                    }
                }
                else{
                    if((word[i]-'a' >= 0) && (word[i]-'a' < 26)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
