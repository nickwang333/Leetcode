class Solution {
public:
    bool check(char i){
        return i=='a' || i=='e' || i=='i' || i=='o' || i=='u';
    }
    
    long long countVowels(string word) {
        long long ret = 0, n = word.size();
        for(int i=0; i<word.size(); i++){
            if(check(word[i])){
                ret += ((i+1)*(n-i));
            }
        }
        return ret;
    }
};
