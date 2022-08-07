class Solution {
public:
    int longestIdealString(string s, int k) {
        map<int,int> m;
        int ret = 0;
        for(char i:s){
            int digit = i-'a';
            int maxi = 0;
            for(int j=0; j<=k; j++){
                maxi = max(maxi,m[digit-j]);
                maxi = max(maxi,m[digit+j]);
            }
            m[digit] = maxi+1;
            ret = max(maxi+1, ret);
        }
        return ret;
    }
};
