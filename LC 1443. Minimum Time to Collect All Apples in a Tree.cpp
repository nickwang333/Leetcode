class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int ret = 0;
        unordered_map<int, vector<int>> adj;
        vector<int> parents(n, -1);
        vector<bool> visited(n, false), has(n, false);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        stack<int> s;
        q.push(0);
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            visited[tmp] = true;
            for(int i:adj[tmp]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                    parents[i] = tmp;
                    s.push(i);
                }
            }
        }
        while(!s.empty()){
            int tmp = s.top();
            s.pop();
            if(hasApple[tmp] || has[tmp]){
                has[parents[tmp]] = true;
                has[tmp] = true;
            }
        }
        q.push(0);
        vector<bool> visited2(n, false);
        visited2[0] = true;
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            for(int i:adj[tmp]){
                if(!visited2[i] && has[i]){
                    
                    visited2[i] = true;
                    q.push(i);
                    ret+=2;
                }
            }
        }
        return ret;
    }
};
