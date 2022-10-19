class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int number = 1, m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    number++;
                    queue<vector<int>> q;
                    vector<int> tmpv{i, j};
                    q.push(tmpv);
                    while(!q.empty()){
                        tmpv = q.front();
                        grid[tmpv[0]][tmpv[1]] = number;
                        q.pop();
                        if(tmpv[0] > 0 && grid[tmpv[0]-1][tmpv[1]] == 1){
                            grid[tmpv[0]-1][tmpv[1]] = number;
                            vector<int> tmp{tmpv[0]-1, tmpv[1]};
                            q.push(tmp);
                        }
                        if(tmpv[1] > 0 && grid[tmpv[0]][tmpv[1]-1] == 1){
                            grid[tmpv[0]][tmpv[1]-1] = number;
                            vector<int> tmp{tmpv[0], tmpv[1]-1};
                            q.push(tmp);
                        }
                        if(tmpv[0] < m-1 && grid[tmpv[0]+1][tmpv[1]] == 1){
                            grid[tmpv[0]+1][tmpv[1]] = number;
                            vector<int> tmp{tmpv[0]+1, tmpv[1]};
                            q.push(tmp);
                        }
                        if(tmpv[1] < n-1 && grid[tmpv[0]][tmpv[1]+1] == 1){
                            grid[tmpv[0]][tmpv[1]+1] = number;
                            vector<int> tmp{tmpv[0], tmpv[1]+1};
                            q.push(tmp);
                        }
                    }
                }
            }
        }
        unordered_map<int, int> m2;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                m2[grid[i][j]]++;
            }
        }
        int ret = 0;
        for(int i=2; i<=number; i++){
            ret = max(ret, m2[i]);
        }
        return ret;
    }
};
