class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        sort(coins.rbegin(), coins.rend());
        int n = coins.size();
        dp[0] = 1;
        for(int i:coins){
            for(int j=0; j<=amount; j++){
                if(dp[j] != 0 && j+i <= amount){
                    dp[j+i] += dp[j];
                }
            }
        }
        return dp[amount];
    }
};
