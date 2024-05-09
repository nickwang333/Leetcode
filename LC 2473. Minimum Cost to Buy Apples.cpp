class Solution {
public:
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        vector<long long> ret(n, INT_MAX);
        unordered_map<int, unordered_map<int, int>> adj;
        for(auto i:roads){
            adj[i[0]][i[1]] = i[2];
            adj[i[1]][i[0]] = i[2];
        }
        for(int i=0; i<n; i++){
            ret[i] = appleCost[i];
            queue<int> q1, q2;
            q1.push(i+1);
            q2.push(0);
            vector<long long> visited(n, INT_MAX);
            visited[i] = 0;
            while(!q1.empty()){
                int tmp1 = q1.front();
                int tmp2 = q2.front();
                q1.pop();
                q2.pop();
                for(auto it:adj[tmp1]){
                    long long costs = appleCost[it.first-1] + (k+1) * (it.second + tmp2);
                    if((it.second + tmp2) < visited[it.first - 1]){
                        visited[it.first - 1] = it.second + tmp2;
                        q1.push(it.first);
                        q2.push(it.second + tmp2);
                    }
                    ret[i] = min(ret[i], costs);
                }
            }
        }
        return ret;
    }
};
