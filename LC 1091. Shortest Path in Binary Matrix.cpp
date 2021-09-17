bool check_valid(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& v){
    int n = grid.size();
    if(i>=0 && i<n && j>=0 && j<n && grid[i][j]==0 && v[i][j]==-1){
        return true;
    }
    return false;
}

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> row(n,-1);
        vector<vector<int>> v(n,row);
        vector<int> tmp{0,0};
        queue<vector<int>> q;
        if(grid[0][0]==0){
            v[0][0] = 1;
            q.push(tmp);
        }
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            int val = v[tmp[0]][tmp[1]]+1;
            vector<int> tmp2(2);
            if(check_valid(tmp[0]+1, tmp[1], grid, v)){
                v[tmp[0]+1][tmp[1]] = val;
                tmp2[0] = tmp[0]+1;
                tmp2[1] = tmp[1];
                q.push(tmp2);
            }
            if(check_valid(tmp[0], tmp[1]+1, grid, v)){
                v[tmp[0]][tmp[1]+1] = val;
                tmp2[0] = tmp[0];
                tmp2[1] = tmp[1]+1;
                q.push(tmp2);
            }
            if(check_valid(tmp[0]+1, tmp[1]+1, grid, v)){
                v[tmp[0]+1][tmp[1]+1] = val;
                tmp2[0] = tmp[0]+1;
                tmp2[1] = tmp[1]+1;
                q.push(tmp2);
            }
            if(check_valid(tmp[0]-1, tmp[1], grid, v)){
                v[tmp[0]-1][tmp[1]] = val;
                tmp2[0] = tmp[0]-1;
                tmp2[1] = tmp[1];
                q.push(tmp2);
            }
            if(check_valid(tmp[0], tmp[1]-1, grid, v)){
                v[tmp[0]][tmp[1]-1] = val;
                tmp2[0] = tmp[0];
                tmp2[1] = tmp[1]-1;
                q.push(tmp2);
            }
            if(check_valid(tmp[0]-1, tmp[1]-1, grid, v)){
                v[tmp[0]-1][tmp[1]-1] = val;
                tmp2[0] = tmp[0]-1;
                tmp2[1] = tmp[1]-1;
                q.push(tmp2);
            }
            if(check_valid(tmp[0]+1, tmp[1]-1, grid, v)){
                v[tmp[0]+1][tmp[1]-1] = val;
                tmp2[0] = tmp[0]+1;
                tmp2[1] = tmp[1]-1;
                q.push(tmp2);
            }
            if(check_valid(tmp[0]-1, tmp[1]+1, grid, v)){
                v[tmp[0]-1][tmp[1]+1] = val;
                tmp2[0] = tmp[0]-1;
                tmp2[1] = tmp[1]+1;
                q.push(tmp2);
            }
        }
        for(auto i:v){
            for(int j:i){
                cout << j;
            }
            cout << endl;
        }
        return v[n-1][n-1];
    }
};
