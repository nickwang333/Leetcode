class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), ret = INT_MAX;
        vector<int> row(n, -1);
        vector<vector<int>> dp(n, row);
        for(int i=0; i<n; i++){
            dp[0][i] = grid[0][i];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(k != j){
                        if(dp[i][j] == -1){
                            dp[i][j] = grid[i][j] + dp[i-1][k];
                        }
                        dp[i][j] = min(dp[i-1][k]+ grid[i][j], dp[i][j]);
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            ret = min(ret, dp[n-1][i]);
        }
        return ret;
    }
};
