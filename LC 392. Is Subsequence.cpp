class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size(), counter = 0;
        for(int i=0; i<n; i++){
            if(t[i] == s[counter]){
                counter++;
            }
            if(counter == m){
                return true;
            }
        }
        if(s == t){
            return true;
        }
        return false;
    }
};
