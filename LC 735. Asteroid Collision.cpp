class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> row(n+1,0), group1(n+1,0), group2(n+1,0);
        vector<vector<int>> adj(n+1,row);
        int counter = 0;
        for(auto i:dislikes){
            adj[i[0]][i[1]] = 1;
            adj[i[1]][i[0]] = 1;
        }
        vector<int> visited(n+1,0);
        queue<int> q;
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                q.push(i);
            }
            while(!q.empty()){
                int sz = q.size();
                for(int i=0; i<sz; i++){
                    int tmp = q.front();
                    if(counter%2==0){
                        group1[tmp] = 1;
                    }
                    else{
                        group2[tmp] = 1;
                    }
                    q.pop();
                    for(int j=0; j<=n; j++){
                        if(visited[j] == 0 && adj[j][tmp] == 1){
                            q.push(j);
                            visited[j] = 1;
                        }
                    }
                }
                counter++;
            }
        }
        for(int i=0; i<=n; i++){
                for(int j=0; j<=n; j++){
                    if(group1[i] == 1 && group1[j] == 1 && adj[i][j] == 1){
                        return false;
                    }
                }
            }
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(group2[i] == 1 && group2[j] == 1 && adj[i][j] == 1){
                    return false;
                }
            }
        }
        return true;
    }
};
