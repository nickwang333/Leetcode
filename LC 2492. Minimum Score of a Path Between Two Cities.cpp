class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ret = INT_MAX;
        unordered_map<int, unordered_map<int,int>> m;
        for(auto i:roads){
            m[i[0]][i[1]] = i[2];
            m[i[1]][i[0]] = i[2];
        }
        queue<int> q;
        q.push(1);
        vector<bool> visited(n+1, false);
        visited[1] = true;
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            for(auto it = m[tmp].begin(); it != m[tmp].end(); it++){
                ret = min(ret, it->second);
                if(!visited[it->first]){
                    q.push(it->first);
                    visited[it->first] = true;
                }
            }
        }
        return ret;
    }
};
