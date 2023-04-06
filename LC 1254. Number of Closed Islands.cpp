class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<int>> v = grid;
        int counter = 2, n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j] == 0){
                    queue<vector<int>> q;
                    vector<int> tmpv{i,j};
                    q.push(tmpv);
                    while(!q.empty()){
                        tmpv = q.front();
                        q.pop();
                        v[tmpv[0]][tmpv[1]] = counter;
                        if(tmpv[0] > 0 && v[tmpv[0]-1][tmpv[1]] == 0){
                            vector<int> tmpv2{tmpv[0]-1, tmpv[1]};
                            v[tmpv[0]-1][tmpv[1]] = counter;
                            q.push(tmpv2);
                        }
                        if(tmpv[1] > 0 && v[tmpv[0]][tmpv[1]-1] == 0){
                            vector<int> tmpv2{tmpv[0], tmpv[1]-1};
                            v[tmpv[0]][tmpv[1]-1] = counter;
                            q.push(tmpv2);
                        }
                        if(tmpv[0] < n-1 && v[tmpv[0]+1][tmpv[1]] == 0){
                            vector<int> tmpv2{tmpv[0]+1, tmpv[1]};
                            v[tmpv[0]+1][tmpv[1]] = counter;
                            q.push(tmpv2);
                        }
                        if(tmpv[1] < m-1 && v[tmpv[0]][tmpv[1]+1] == 0){
                            vector<int> tmpv2{tmpv[0], tmpv[1]+1};
                            v[tmpv[0]][tmpv[1]+1] = counter;
                            q.push(tmpv2);
                        }
                    }
                    counter++;
                }
            }
        }
        vector<int> visited(counter, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //cout << v[i][j] << " ";
                if(v[i][j] != 1){
                    if(i == 0 || j == 0 || i == n-1 || j == m-1){
                        visited[v[i][j]] = 1;
                    }
                }
            }
            //cout << endl;
        }
        int ret = 0;
        for(int i=2; i<visited.size(); i++){
            if(visited[i] == 0){
                ret++;
            }
        }
        return ret;
    }
};
