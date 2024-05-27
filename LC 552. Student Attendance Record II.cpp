class Solution {
public:
    int checkRecord(int n) {
        int mod = 1000000007;
        long ret = 0;
        if(n == 1){
            return 3;
        }
        if(n == 2){
            return 8;
        }
        vector<long> dp1(n, 0), dp2(n, 0), dp0(n, 0);
        vector<long> dp1a(n, 0), dp2a(n, 0), dp0a(n, 0);
        dp0[0] = 1;
        dp1[0] = 1;

        dp0a[0] = 1;
        for(int i=1; i<n; i++){
            dp0[i] = dp0[i-1] + dp1[i-1] + dp2[i-1];
            dp0[i] %= mod;
            dp1[i] = dp0[i-1];
            dp1[i] %= mod;
            dp2[i] = dp1[i-1];
            dp2[i] %= mod;

            dp0a[i] = dp0[i-1] + dp0a[i-1] + dp1a[i-1] + dp2a[i-1] + dp1[i-1] + dp2[i-1];
            dp0a[i] %= mod;
            dp1a[i] = dp0a[i-1];
            dp1a[i] %= mod;
            dp2a[i] = dp1a[i-1];
            dp2a[i] %= mod;
        }
        ret += dp0[n-1];
        ret %= mod;
        ret += dp1[n-1];
        ret %= mod;
        ret += dp2[n-1];
        ret %= mod;
        ret += dp0a[n-1];
        ret %= mod;
        ret += dp1a[n-1];
        ret %= mod;
        ret += dp2a[n-1];
        ret %= mod;
        return ret;
    }
};
