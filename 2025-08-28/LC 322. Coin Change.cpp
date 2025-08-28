class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for(int i:coins){
            for(int j=0; j<=amount; j++) {
                if(dp[j] != -1 && long(j)+long(i) <= long(amount)){
                    if(dp[j+i] == -1){
                        dp[j+i] = dp[j]+1;
                    }
                    else{
                        dp[j+i] = min(dp[j+i], dp[j]+1);
                    }
                }
            }
        }
        return dp[amount];
    }
};
