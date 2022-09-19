class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size(), ret = 1, tmp = 1;
        for(int i = 1; i<n; i++){
            int diff = s[i]-s[i-1];
            if(diff == 1){
                tmp++;
                ret = max(ret, tmp);
            }
            else{
                tmp = 1;
            }
        }
        return ret;
    }
};
