class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ret = 0;
        vector<int> row(m, 0);
        for(int i=0; i<m; i++){
            if(grid[i][0] == 0){
                row[i] = 1;
            }
            ret += pow(2, n-1);
        }
        for(int i=1; i<n; i++){
            int total = 0;
            for(int j=0; j<m; j++){
                if((grid[j][i] == 1 && row[j] == 0) || (grid[j][i] == 0 && row[j] == 1)){
                    total++;
                }
            }
            total = max(total, m - total);
            ret += (pow(2, n-1-i) * total);
        }
        return ret;
    }
};
