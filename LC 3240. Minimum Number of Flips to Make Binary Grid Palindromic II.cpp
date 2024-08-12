class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ret = 0;
        for(int i=0; i<m/2; i++){
            for(int j=0; j<n/2; j++){
                int tsum = grid[i][j] + grid[m-i-1][j] + grid[i][n-j-1] + grid[m-i-1][n-j-1];
                ret += min(4-tsum, tsum);
            }
        }
        if(m%2 == 1 && n%2 == 1){
            ret += grid[m/2][n/2];
        }
        int tsum = 0, diff = 0;
        if(m%2 == 1){
            for(int i=0; i<n/2; i++){
                if(grid[m/2][i] != grid[m/2][n-i-1]){
                    diff++;
                    ret++;
                }
                tsum += grid[m/2][i];
                tsum += grid[m/2][n-i-1];
            }
        }
        if(n%2 == 1){
            for(int i=0; i<m/2; i++){
                if(grid[i][n/2] != grid[m-i-1][n/2]){
                    diff++;
                    ret++;
                }
                tsum += grid[i][n/2];
                tsum += grid[m-i-1][n/2];
            }
        }
        if(diff == 0){
            ret += min(tsum%4, 4 - tsum%4);
        }
        return ret;
    }
};
