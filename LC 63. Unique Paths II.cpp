class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> row(n+1,0);
        vector<vector<int>> dp(m+1,row);
        dp[1][1] = 1;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(obstacleGrid[i-1][j-1]!=1){
                    dp[i][j] += dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
