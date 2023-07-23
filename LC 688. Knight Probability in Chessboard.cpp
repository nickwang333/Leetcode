class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        double ret = 0;
        vector<double> row2(n, 0);
        vector<vector<double>> dp(n, row2);
        dp[row][column] = 1;
        for(int i=0; i<k; i++){
            vector<vector<double>> tmp(n, row2);
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(dp[j][k] != 0){
                        if(j > 0 && k > 1){
                            tmp[j-1][k-2] += dp[j][k]/8;
                        }
                        if(j > 0 && k < n-2){
                            tmp[j-1][k+2] += dp[j][k]/8;
                        }
                        if(j > 1 && k > 0){
                            tmp[j-2][k-1] += dp[j][k]/8;
                        }
                        if(j > 1 && k < n-1){
                            tmp[j-2][k+1] += dp[j][k]/8;
                        }
                        if(j < n-1 && k > 1){
                            tmp[j+1][k-2] += dp[j][k]/8;
                        }
                        if(j < n-1 && k < n-2){
                            tmp[j+1][k+2] += dp[j][k]/8;
                        }
                        if(j < n-2 && k < n-1){
                            tmp[j+2][k+1] += dp[j][k]/8;
                        }
                        if(j < n-2 && k > 0){
                            tmp[j+2][k-1] += dp[j][k]/8;
                        }
                    }
                }
            }
            dp = tmp;
        }
        for(auto i:dp){
            for(double j:i){
                ret += j;
                //cout << j << " ";
            }
            //cout << endl;
        }
        return ret;
    }
};
