class Solution {
public:
    bool check_valid(vector<vector<int>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        if(i>=m || i<0 || j>=n || j<0 || grid[i][j]!=1){
            return false;
        }
        grid[i][j] = 2;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        vector<int> v(2);
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    v[0] = i;
                    v[1] = j;
                    q.push(v);
                }
            }
        }
        int counter = -1;
        if(q.empty()){
            counter = 0;
        }
        while(!q.empty()){
            counter++;
            int sz = q.size();
            for(int i=0; i<sz; i++){
                vector<int> tmp = q.front();
                q.pop();
                if(check_valid(grid, tmp[0]+1, tmp[1])){
                    vector<int> tmp2(2);
                    tmp2[0] = tmp[0]+1;
                    tmp2[1] = tmp[1];
                    q.push(tmp2);
                }
                if(check_valid(grid, tmp[0], tmp[1]+1)){
                    vector<int> tmp2(2);
                    tmp2[0] = tmp[0];
                    tmp2[1] = tmp[1]+1;
                    q.push(tmp2);
                }
                if(check_valid(grid, tmp[0]-1, tmp[1])){
                    vector<int> tmp2(2);
                    tmp2[0] = tmp[0]-1;
                    tmp2[1] = tmp[1];
                    q.push(tmp2);
                }
                if(check_valid(grid, tmp[0], tmp[1]-1)){
                    vector<int> tmp2(2);
                    tmp2[0] = tmp[0];
                    tmp2[1] = tmp[1]-1;
                    q.push(tmp2);
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return counter;
    }
};
