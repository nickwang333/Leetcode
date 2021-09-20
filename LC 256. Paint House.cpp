class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> v(3,0);
        vector<vector<int>> dp(n,v);
        for(int i=0; i<n; i++){
            for(int j=0; j<3; j++){
                if(i==0){
                    dp[i][j] = costs[i][j];
                }
                else{
                    if(j==0){
                        dp[i][j] = min(dp[i-1][1], dp[i-1][2])+costs[i][j];
                    }
                    if(j==1){
                        dp[i][j] = min(dp[i-1][0], dp[i-1][2])+costs[i][j];
                    }
                    if(j==2){
                        dp[i][j] = min(dp[i-1][1], dp[i-1][0])+costs[i][j];
                    }
                }
            }
        }
        return min(min(dp[n-1][0], dp[n-1][1]),dp[n-1][2]);
    }
};
