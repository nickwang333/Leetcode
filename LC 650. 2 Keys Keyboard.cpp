class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, INT_MAX);
        if(n == 1){
            return 0;
        }
        dp[1] = 0;
        dp[2] = 2;
        int ret = 0;
        for(int i=1; i<n; i++){
            int counter = 2;
            for(int j=i+i; j<=n; j += i){
                dp[j] = min(dp[j], dp[i] + counter);
                counter++;
            }
        }
        return dp[n];
    }
};
