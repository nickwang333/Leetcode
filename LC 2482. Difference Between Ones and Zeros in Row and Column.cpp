class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m, 0), col(n, 0);
        vector<vector<int>> diff = grid;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                diff[i][j] = 2*(row[i] + col[j]) - m - n;
            }
        }
        return diff;
    }
};
