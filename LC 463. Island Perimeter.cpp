class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ret = 0, row = grid.size(), col = grid[0].size();
        vector<vector<int>> visited = grid;
        queue<int> q1, q2;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    ret += 4;
                    if(i > 0){
                        ret -= grid[i-1][j];
                    }
                    if(i<row-1){
                        ret -= grid[i+1][j];
                    }
                    if(j > 0){
                        ret -= grid[i][j-1];
                    }
                    if(j < col-1){
                        ret -= grid[i][j+1];
                    }
                }
            }
        }
        return ret;
    }
};
