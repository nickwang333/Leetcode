class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size(), len = 1;
        string sr = s;
        reverse(sr.begin(), sr.end());
        vector<int> v(n+1, 0);
        vector<vector<int>> dp(n+1, v);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(s[i] == sr[j]){
                    dp[i+1][j+1] = max(dp[i][j]+1, dp[i+1][j+1]);
                    len = max(len, dp[i+1][j+1]);
                }
                else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return len;
    }
};
