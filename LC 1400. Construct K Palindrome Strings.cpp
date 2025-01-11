class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        vector<int> v(26, 0);
        for(char i:s){
            v[i-'a']++;
        }
        if(k > n){
            return false;
        }
        int mini = 0;
        for(int i:v){
            if(i % 2 == 1){
                mini++;
            }
        }
        if(mini > k){
            return false;
        }
        return true;
    }
};
