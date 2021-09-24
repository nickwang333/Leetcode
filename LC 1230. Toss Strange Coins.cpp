class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<double> row(n,0);
        vector<vector<double>> dp(target+1, row);
        for(int i=0; i<=target; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    dp[i][j] = 1-prob[j];
                }
                else if(i==0){
                    dp[i][j] = (1-prob[j])*dp[i][j-1];
                }
                else if(j<i-1){
                    continue;
                }
                else if(j==0){
                    dp[i][j] = prob[j];
                }
                else{
                    dp[i][j] = prob[j]*dp[i-1][j-1]+(1-prob[j])*dp[i][j-1];
                }
            }
        }
        return dp[target][n-1];
    }
};
