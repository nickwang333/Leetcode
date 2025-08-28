class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), counter = 2, ret = 1;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    int total = 0;
                    queue<vector<int>> q;
                    q.push(vector<int> {i, j});
                    while(!q.empty()){
                        vector<int> tmp = q.front();
                        grid[tmp[0]][tmp[1]] = counter;
                        q.pop();
                        total++;
                        if(tmp[0] > 0 && grid[tmp[0]-1][tmp[1]] == 1){
                            q.push(vector<int> {tmp[0]-1, tmp[1]});
                            grid[tmp[0]-1][tmp[1]] = counter;
                        }
                        if(tmp[0] < n-1 && grid[tmp[0]+1][tmp[1]] == 1){
                            q.push(vector<int> {tmp[0]+1, tmp[1]});
                            grid[tmp[0]+1][tmp[1]] = counter;
                        }
                        if(tmp[1] > 0 && grid[tmp[0]][tmp[1]-1] == 1){
                            q.push(vector<int> {tmp[0], tmp[1]-1});
                            grid[tmp[0]][tmp[1]-1] = counter;
                        }
                        if(tmp[1] < n-1 && grid[tmp[0]][tmp[1]+1] == 1){
                            q.push(vector<int> {tmp[0], tmp[1]+1});
                            grid[tmp[0]][tmp[1]+1] = counter;
                        }
                    }
                    m[counter] = total;
                    ret = max(ret, total);
                    counter++;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    unordered_map<int, int> m2;
                    int tmp = 1;
                    if(i > 0){
                        m2[grid[i-1][j]] = 1;
                    }
                    if(j > 0){
                        m2[grid[i][j-1]]++;
                    }
                    if(i < n-1){
                        m2[grid[i+1][j]]++;
                    }
                    if(j < n-1){
                        m2[grid[i][j+1]]++;
                    }
                    for(auto it:m2){
                        tmp += m[it.first];
                    }
                    ret = max(ret, tmp);
                }
            }
        }
        return ret;
    }
};
