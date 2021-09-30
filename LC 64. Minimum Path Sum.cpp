class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(n+1,0);
        vector<vector<int>> dp(m+1,row);
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(i==1){
                    dp[i][j] = dp[i][j-1]+grid[i-1][j-1];
                }
                else if(j==1){ 
                     dp[i][j] = dp[i-1][j]+grid[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1])+grid[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
