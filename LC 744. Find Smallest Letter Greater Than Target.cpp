class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ret = letters[0];
        for(int i=1; i<letters.size(); i++){
            if(letters[i] > target && ret <= target){
                ret = letters[i];
                return ret;
            }
        }
        return ret;
    }
};
