class Solution {
    int ret = 0;
public:
    void backtracking(vector<vector<int>>& grid, vector<vector<int>>& visited, vector<int>& pos, int current){
        int m = grid.size(), n = grid[0].size();
        if(pos[0] < m-1 && visited[pos[0]+1][pos[1]] == 0 && grid[pos[0]+1][pos[1]] != 0){
            vector<vector<int>> tmpVisited = visited;
            vector<int> tmpPos{pos[0]+1, pos[1]};
            int tmpCurrent = current + grid[pos[0]+1][pos[1]];
            tmpVisited[pos[0]+1][pos[1]] = 1;
            ret = max(ret, tmpCurrent);
            backtracking(grid,tmpVisited, tmpPos, tmpCurrent);
        }
        if(pos[1] < n-1 && visited[pos[0]][pos[1]+1] == 0 && grid[pos[0]][pos[1]+1] != 0){
            vector<vector<int>> tmpVisited = visited;
            vector<int> tmpPos{pos[0], pos[1]+1};
            int tmpCurrent = current + grid[pos[0]][pos[1]+1];
            tmpVisited[pos[0]][pos[1]+1] = 1;
            ret = max(ret, tmpCurrent);
            backtracking(grid,tmpVisited, tmpPos, tmpCurrent);
        }
        if(pos[0] > 0 && visited[pos[0]-1][pos[1]] == 0 && grid[pos[0]-1][pos[1]] != 0){
            vector<vector<int>> tmpVisited = visited;
            vector<int> tmpPos{pos[0]-1, pos[1]};
            int tmpCurrent = current + grid[pos[0]-1][pos[1]];
            tmpVisited[pos[0]-1][pos[1]] = 1;
            ret = max(ret, tmpCurrent);
            backtracking(grid,tmpVisited, tmpPos, tmpCurrent);
        }
        if(pos[1] > 0 && visited[pos[0]][pos[1]-1] == 0 && grid[pos[0]][pos[1]-1] != 0){
            vector<vector<int>> tmpVisited = visited;
            vector<int> tmpPos{pos[0], pos[1]-1};
            int tmpCurrent = current + grid[pos[0]][pos[1]-1];
            tmpVisited[pos[0]][pos[1]-1] = 1;
            ret = max(ret, tmpCurrent);
            backtracking(grid,tmpVisited, tmpPos, tmpCurrent);
        }
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(n, 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 0){
                    vector<int> pos{i, j};
                    vector<vector<int>> visited(m, row);
                    visited[i][j] = 1;
                    ret = max(ret, grid[i][j]);
                    backtracking(grid,visited, pos, grid[i][j]);
                }
            }
        }
        return ret;
    }
};
