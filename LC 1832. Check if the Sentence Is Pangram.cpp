class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> v(26,0);
        for(char i:sentence){
            v[i-'a']++;
        }
        for(int i:v){
            if(i==0){
                return false;
            }
        }
        return true;
    }
};
