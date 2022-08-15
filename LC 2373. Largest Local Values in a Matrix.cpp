class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> row(n-2,0);
        vector<vector<int>> ret(n-2, row);
        for(int i=1; i<n-1; i++){
            for(int j=1; j<n-1; j++){
                int tmp = max(grid[i-1][j-1], max(grid[i][j-1], grid[i+1][j-1]));
                int tmp2 = max(grid[i-1][j], max(grid[i][j], grid[i+1][j]));
                int tmp3 = max(grid[i-1][j+1], max(grid[i][j+1], grid[i+1][j+1]));
                int tmp4 = max(tmp, max(tmp2, tmp3));
                ret[i-1][j-1] = tmp4;
            }
        }
        return ret;
    }
};
