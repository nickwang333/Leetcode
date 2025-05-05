class Solution {
public:
    int numTilings(int n) {
        int mod = 1000000007;
        vector<long> dp(1001, 1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-3] + 2*dp[i-1];
            dp[i] %= mod;
        }
        return dp[n];
    }
};
