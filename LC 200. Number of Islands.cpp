bool check_valid(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& v){
    int m = grid.size(), n = grid[0].size();
    if(r>=0 && r<m && c>=0 && c<n && v[r][c] == -1 && grid[r][c]=='1'){
        return true;
    }
    return false;
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(n,-1);
        int ret = 0;
        vector<vector<int>> v(m,row);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(check_valid(i, j, grid, v)){
                    v[i][j] = ret;
                    queue<vector<int>> q;
                    vector<int> tmp{i, j};
                    q.push(tmp);
                    while(!q.empty()){
                        vector<int> v1 = q.front();
                        q.pop();
                        if(check_valid(v1[0]+1, v1[1], grid, v)){
                            v[v1[0]+1][v1[1]] = ret;
                            tmp[0] = v1[0]+1;
                            tmp[1] = v1[1];
                            q.push(tmp);
                        }
                        if(check_valid(v1[0], v1[1]+1, grid, v)){
                            v[v1[0]][v1[1]+1] = ret;
                            tmp[0] = v1[0];
                            tmp[1] = v1[1]+1;
                            q.push(tmp);
                        }
                        if(check_valid(v1[0]-1, v1[1], grid, v)){
                            v[v1[0]-1][v1[1]] = ret;
                            tmp[0] = v1[0]-1;
                            tmp[1] = v1[1];
                            q.push(tmp);
                        }
                        if(check_valid(v1[0], v1[1]-1, grid, v)){
                            v[v1[0]][v1[1]-1] = ret;
                            tmp[0] = v1[0];
                            tmp[1] = v1[1]-1;
                            q.push(tmp);
                        }
                    }
                    ret++;
                }
            }
        }
        return ret;
    }
};
