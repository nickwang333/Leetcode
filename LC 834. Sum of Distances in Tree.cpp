class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj, levels;
        unordered_map<int, int> parent;
        vector<int> ret(n, 0);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int level = 0;
        queue<int> q;
        q.push(0);
        vector<int> visited(n, 0);
        visited[0] = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int tmp = q.front();
                levels[level].push_back(tmp);
                visited[tmp] = 1;
                q.pop();
                for(int j:adj[tmp]){
                    if(visited[j] == 0){
                        parent[j] = tmp;
                        q.push(j);
                        visited[j] = 1;
                    }
                }
            }
            level++;
        }
        vector<int> count(n, 1);
        for(int i=level-1; i>0; i--){
            for(int j:levels[i]){
                count[parent[j]] += count[j];
                ret[0] += i;
            }
        }
        queue<int> cnt;
        q.push(0);
        vector<int> visited2(n, 0);
        visited2[0] = 1;
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            for(int i:adj[tmp]){
                if(visited2[i] == 0){
                    q.push(i);
                    visited2[i] = 1;
                    int newVal = ret[tmp] + (n-count[i]) - count[i];
                    ret[i] = newVal;
                }
            }
        }
        return ret;
    }
};
