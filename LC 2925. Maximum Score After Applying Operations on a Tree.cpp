class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = edges.size();
        long long ret = 0;
        vector<long long> dp(n+1, 0);
        unordered_map<int, vector<int>> child, adj, level;
        unordered_map<int, int> parent;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        vector<int> visited(n+1, 0);
        q.push(0);
        int counter = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int j=0; j<sz; j++){
                int tmp = q.front();
                level[counter].push_back(tmp);
                q.pop();
                visited[tmp] = 1;
                for(auto i:adj[tmp]){
                    if(visited[i] == 0){
                        q.push(i);
                        child[tmp].push_back(i);
                        parent[i] = tmp;
                        visited[i] = 1;
                    }
                }
            }
            counter++;
        }
        
        for(int i=counter-1; i>=0; i--){
            for(int j:level[i]){
                if(child[j].size() == 0){
                    dp[j] = values[j];
                }
                else{
                    long long tmp = 0, tmp2 = values[j];
                    for(int k:child[j]){
                        tmp += dp[k];
                    }
                    dp[j] = min(tmp2, tmp);
                }
            }
        }
        long long tmp = 0;
        for(int i: values){
            tmp += i;
        }
        return tmp-dp[0];
    }
};
