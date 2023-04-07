class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> v = grid;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j] == 1){
                    if(i == 0 || i == n-1 || j == 0 || j == m-1){
                        v[i][j] = 2;
                        queue<vector<int>> q;
                        vector<int> tmpv{i, j};
                        q.push(tmpv);
                        while(!q.empty()){
                            vector<int> tmp = q.front();
                            q.pop();
                            if(tmp[0]>0 && v[tmp[0]-1][tmp[1]] == 1){
                                vector<int> tmp2{tmp[0]-1, tmp[1]};
                                v[tmp[0]-1][tmp[1]] = 2;
                                q.push(tmp2);
                            }
                            if(tmp[1]>0 && v[tmp[0]][tmp[1]-1] == 1){
                                vector<int> tmp2{tmp[0], tmp[1]-1};
                                v[tmp[0]][tmp[1]-1] = 2;
                                q.push(tmp2);
                            }
                            if(tmp[0]<n-1 && v[tmp[0]+1][tmp[1]] == 1){
                                vector<int> tmp2{tmp[0]+1, tmp[1]};
                                v[tmp[0]+1][tmp[1]] = 2;
                                q.push(tmp2);
                            }
                            if(tmp[1]<m-1 && v[tmp[0]][tmp[1]+1] == 1){
                                vector<int> tmp2{tmp[0], tmp[1]+1};
                                v[tmp[0]][tmp[1]+1] = 2;
                                q.push(tmp2);
                            }
                        }
                    }
                }
            }
        }
        int ret = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j] == 1){
                    ret++;
                }
            }
        }
        return ret;
    }
};
