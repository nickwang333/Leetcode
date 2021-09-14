bool check_valid(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& v){
    int m = grid.size(), n = grid[0].size();
    if(r<m && r>=0 && c<n && c>=0 && grid[r][c]!='X' && v[r][c]==-1){
        return true;
    }
    return false;
}

class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int r,c,m = grid.size(), n = grid[0].size();
        vector<int> row(n,-1);
        vector<vector<int>> v(m,row);
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='*'){
                    r = i;
                    c = j;
                    v[r][c] = 0;
                }
            }
        }
        
        vector<int> tmp(2); tmp[0] = r; tmp[1] = c;
        queue<vector<int>> q;
        q.push(tmp);
        while(!q.empty()){
            vector<int> v1 = q.front();
            q.pop();
            if(check_valid(v1[0]+1, v1[1], grid, v)){
                tmp[0] = v1[0]+1;
                tmp[1] = v1[1];
                v[tmp[0]][tmp[1]] = v[v1[0]][v1[1]]+1;
                if(grid[tmp[0]][tmp[1]]=='#'){
                    return v[tmp[0]][tmp[1]];
                }
                q.push(tmp);
            }
            if(check_valid(v1[0], v1[1]+1, grid, v)){
                tmp[0] = v1[0];
                tmp[1] = v1[1]+1;
                v[tmp[0]][tmp[1]] = v[v1[0]][v1[1]]+1;
                if(grid[tmp[0]][tmp[1]]=='#'){
                    return v[tmp[0]][tmp[1]];
                }
                q.push(tmp);
            }
            if(check_valid(v1[0]-1, v1[1], grid, v)){
                tmp[0] = v1[0]-1;
                tmp[1] = v1[1];
                v[tmp[0]][tmp[1]] = v[v1[0]][v1[1]]+1;
                if(grid[tmp[0]][tmp[1]]=='#'){
                    return v[tmp[0]][tmp[1]];
                }
                q.push(tmp);
            }
            if(check_valid(v1[0], v1[1]-1, grid, v)){
                tmp[0] = v1[0];
                tmp[1] = v1[1]-1;
                v[tmp[0]][tmp[1]] = v[v1[0]][v1[1]]+1;
                if(grid[tmp[0]][tmp[1]]=='#'){
                    return v[tmp[0]][tmp[1]];
                }
                q.push(tmp);
            }
        }
        
        return -1;
    }
};
