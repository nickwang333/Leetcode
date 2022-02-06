class Solution {
public:
    int minimumTime(string s) {
        int n = s.size(), left = 0, ret = n;
        for(int i=0; i<n; i++){
            left = min(i+1, left+(s[i]-'0')*2);
            ret = min(ret, left+n-i-1);
        }
        return ret;
    }
};
