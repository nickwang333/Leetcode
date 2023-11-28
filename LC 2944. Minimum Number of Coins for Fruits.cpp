class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, INT_MAX), dp2(n, INT_MAX);
        //dp include the current one, dp2 exclude the current one
        for(int i=0; i<n; i++){
            if(i == 0){
                dp[i] = prices[i];
                dp2[i] = prices[i];
            }
            else{
                dp[i] = prices[i]+dp2[i-1];
                dp[i] = min(prices[i]+dp[i-1], dp[i]);
            }
            for(int j=i+1; j<min(n, 2*i+2); j++){
                dp2[j] = min(dp[i], dp2[j]);
            }
        }
        return min(dp2[n-1], dp[n-1]);
    }
};
