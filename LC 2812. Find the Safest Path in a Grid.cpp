class Solution {
public:
    bool available(int mid, vector<vector<int>>& dp){
        queue<vector<int>> q;
        int n = dp.size();
        q.push(vector<int>{0,0});
        vector<int> row(n, 0);
        vector<vector<int>> visited(n, row);
        if(dp[0][0] < mid || dp[n-1][n-1] < mid){
            return false;
        }
        while(!q.empty()){
            vector<int> tmp = q.front();
            visited[tmp[0]][tmp[1]] = 1;
            if(tmp[0] == n-1 && tmp[1] == n-1){
                return true;
            }
            q.pop();
            if(tmp[0] > 0 && dp[tmp[0]-1][tmp[1]] >= mid && visited[tmp[0]-1][tmp[1]] == 0){
                q.push(vector<int> {tmp[0]-1, tmp[1]});
                visited[tmp[0]-1][tmp[1]] = 1;
            }
            if(tmp[1] > 0 && dp[tmp[0]][tmp[1]-1] >= mid && visited[tmp[0]][tmp[1]-1] == 0){
                q.push(vector<int> {tmp[0], tmp[1]-1});
                visited[tmp[0]][tmp[1]-1] = 1;
            }
            if(tmp[0] < n-1 && dp[tmp[0]+1][tmp[1]] >= mid && visited[tmp[0]+1][tmp[1]] == 0){
                visited[tmp[0]+1][tmp[1]] = 1;
                q.push(vector<int> {tmp[0]+1, tmp[1]});
            }
            if(tmp[1] < n-1 && dp[tmp[0]][tmp[1]+1] >= mid && visited[tmp[0]][tmp[1]+1] == 0){
                visited[tmp[0]][tmp[1]+1] = 1;
                q.push(vector<int> {tmp[0], tmp[1]+1});
            }
        }
        return false;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size(), ret = 0, high = 0, low = 0;
        queue<vector<int>> q;
        vector<int> row(n, -1);
        vector<vector<int>> dp(n, row);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push(vector<int> {i, j});
                    dp[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                vector<int> tmp = q.front();
                q.pop();
                high = max(high, dp[tmp[0]][tmp[1]]);
                if(tmp[0] > 0 && dp[tmp[0]-1][tmp[1]] == -1){
                    dp[tmp[0]-1][tmp[1]] = dp[tmp[0]][tmp[1]] + 1;
                    q.push(vector<int> {tmp[0]-1, tmp[1]});
                }
                if(tmp[1] > 0 && dp[tmp[0]][tmp[1]-1] == -1){
                    dp[tmp[0]][tmp[1]-1] = dp[tmp[0]][tmp[1]] + 1;
                    q.push(vector<int> {tmp[0], tmp[1]-1});
                }
                if(tmp[0] < n-1 && dp[tmp[0]+1][tmp[1]] == -1){
                    dp[tmp[0]+1][tmp[1]] = dp[tmp[0]][tmp[1]] + 1;
                    q.push(vector<int> {tmp[0]+1, tmp[1]});
                }
                if(tmp[1] < n-1 && dp[tmp[0]][tmp[1]+1] == -1){
                    dp[tmp[0]][tmp[1]+1] = dp[tmp[0]][tmp[1]] + 1;
                    q.push(vector<int> {tmp[0], tmp[1]+1});
                }
            }
        }
        while(high > low){
            int mid = (high+low)/2+1;
            if(available(mid, dp)){
                low = mid;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};
