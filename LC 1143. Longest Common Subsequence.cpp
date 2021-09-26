class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size(),ret=0;
        vector<int> row(n,0);
        vector<vector<int>> dp(m,row);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    if(text1[i] == text2[j]){
                        dp[i][j] = 1;
                    }
                }
                else if(i==0){
                    dp[i][j] = dp[i][j-1];
                    if(text1[i] == text2[j]){
                        dp[i][j] = 1;
                    }
                }
                else if(j==0){
                    dp[i][j] = dp[i-1][j];
                    if(text1[i] == text2[j]){
                        dp[i][j] = 1;
                    }
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                    if(text1[i] == text2[j]){
                        dp[i][j] = dp[i-1][j-1]+1;
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};
