class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s2.size(), m = s1.size(), sz = s3.size();
        if(m+n != sz){
            return false;
        }
        // 0 0 0 0 0 0
        // 0 0 0 0 0 0
        // 0 0 0 0 0 0
        // 0 0 0 0 0 0
        // 0 0 0 0 0 0
        vector<bool> row(n+1,false);
        vector<vector<bool>> dp(m+1, row);
        dp[0][0] = true;
        for(int i=0; i<m; i++){
            if(s1[i] == s3[i] && dp[i][0]){
                dp[i+1][0] = true;
            }
        }
        for(int i=0; i<n; i++){
            if(s2[i] == s3[i] && dp[0][i]){
                dp[0][i+1] = true;
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(s1[i] == s3[i+j+1] && dp[i][j+1]){
                    dp[i+1][j+1] = true;
                } 
                if(s2[j] == s3[j+i+1] && dp[i+1][j]){
                    dp[i+1][j+1] = true;
                }
            }
        }
        
        return dp[m][n];
    }
};
