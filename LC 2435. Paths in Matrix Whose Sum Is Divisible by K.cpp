class Solution {
public:
    vector<int> shift(vector<int>& v, int k){
        vector<int> ret = v;
        for(int i=0; i<v.size(); i++){
            ret[(i+k)%v.size()] = v[i];
        }
        return ret;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), mod = 1000000007;
        vector<int> remainder(k,0);
        vector<vector<int>> row(n, remainder);
        vector<vector<vector<int>>> dp(m, row);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j == 0){
                    dp[i][j][grid[i][j]%k] = 1;
                }
                else if(i==0){
                    int tmp = grid[i][j]%k;
                    vector<int> tmp2 = shift(dp[i][j-1], tmp);
                    dp[i][j] = tmp2;
                } 
                else if(j == 0){
                    int tmp = grid[i][j]%k;
                    vector<int> tmp2 = shift(dp[i-1][j], tmp);
                    dp[i][j]= tmp2;
                }
                else{
                    int tmp = grid[i][j]%k;
                    vector<int> tmp2 = shift(dp[i-1][j], tmp);
                    vector<int> tmp3 = shift(dp[i][j-1], tmp);
                    for(int tmp4 = 0; tmp4<k; tmp4++){
                        dp[i][j][tmp4] += tmp2[tmp4];
                        dp[i][j][tmp4] += tmp3[tmp4];
                        dp[i][j][tmp4] %= mod;
                    }
                }
            }
        }
        return dp[m-1][n-1][0] % mod;
    }
};
