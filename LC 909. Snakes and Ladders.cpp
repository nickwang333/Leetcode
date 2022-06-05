class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int> q;
        int n = board[0].size(), counter = 0;
        vector<int> v(n*n);
        vector<bool> visited(n*n+1, false);
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                if((n-i)%2 == 1){
                    v[(n-i-1)*n+j] = board[i][j];
                }
                else{
                     v[(n-i-1)*n+j] = board[i][n-1-j];
                }
            }
        }
        q.push(1);
        visited[1] = true;
        while(!q.empty()){
            int sz2 = q.size();
            for(int i=0; i<sz2; i++){
                int tmp = q.front();
                q.pop();
                if(tmp == n*n){
                    return counter;
                }
                for(int j = tmp+1; j<=min(tmp+6,n*n); j++){
                    int dest;
                    if(v[j-1] == -1){
                        dest = j;
                    }
                    else{
                        dest = v[j-1];
                    }
                    if(!visited[dest]){
                        q.push(dest);
                    }
                    visited[dest] = true;
                }
            }
            counter++;
        }
        return -1;
    }
};
