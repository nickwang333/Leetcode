class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), tmp = 0, ret = 0;
        for(int i=0; i<m-2; i++){
            tmp = 0;
            tmp += grid[i][0];
            tmp += grid[i][1];
            tmp += grid[i][2];
            tmp += grid[i+1][1];
            tmp += grid[i+2][0];
            tmp += grid[i+2][1];
            tmp += grid[i+2][2];
            ret = max(ret, tmp);
            for(int j=1; j<n-2; j++){
                tmp -= grid[i][j-1];
                tmp -= grid[i+2][j-1];
                tmp -= grid[i+1][j];
                tmp += grid[i][j+2];
                tmp += grid[i+2][j+2];
                tmp += grid[i+1][j+1];
                ret = max(tmp, ret);
            }
        }
        return ret;
    }
};
