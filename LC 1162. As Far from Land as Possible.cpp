class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int n = grid.size();
        vector<int> row(n, -1);
        vector<vector<int>> visited(n, row);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    vector<int> tmp{i,j};
                    q.push(tmp);
                    visited[i][j] = 0;
                }
            }
        }
        if(q.size() == n*n){
            return -1;
        }
        int ret = -1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                vector<int> tmp = q.front();
                q.pop();
                ret = max(ret, visited[tmp[0]][tmp[1]]);
                if(tmp[0] > 0 && visited[tmp[0]-1][tmp[1]] == -1){
                    vector<int> tmp2{tmp[0]-1, tmp[1]};
                    q.push(tmp2);
                    visited[tmp[0]-1][tmp[1]] = visited[tmp[0]][tmp[1]]+1;
                }
                if(tmp[1] > 0 && visited[tmp[0]][tmp[1]-1] == -1){
                    vector<int> tmp2{tmp[0], tmp[1]-1};
                    q.push(tmp2);
                    visited[tmp[0]][tmp[1]-1] = visited[tmp[0]][tmp[1]]+1;
                }
                if(tmp[0] < n-1 && visited[tmp[0]+1][tmp[1]] == -1){
                    vector<int> tmp2{tmp[0]+1, tmp[1]};
                    q.push(tmp2);
                    visited[tmp[0]+1][tmp[1]] = visited[tmp[0]][tmp[1]]+1;
                }
                if(tmp[1] < n-1 && visited[tmp[0]][tmp[1]+1] == -1){
                    vector<int> tmp2{tmp[0], tmp[1]+1};
                    q.push(tmp2);
                    visited[tmp[0]][tmp[1]+1] = visited[tmp[0]][tmp[1]]+1;
                }
            }
        }
        
        return ret;
    }
};
