class Solution {
public:
    int countHomogenous(string s) {
        int ret = 0, n = s.size(), tmp = 1, mod = 1000000007;
        vector<long> dp(n, 1);
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]){
                tmp++;
                dp[i] = dp[i-1] + tmp;
                dp[i] %= mod;
            }
            else{
                ret+=dp[i-1];
                tmp = 1;
                ret %= mod;
            }
        }
        ret+=dp[n-1];
        tmp = 1;
        ret %= mod;
        return ret;
    }
};
