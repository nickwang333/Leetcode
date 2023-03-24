class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int ret = 0, one = -1, two = -1;
        unordered_map<int, vector<int>> parent, child;
        for(auto i:connections){
            child[i[0]].push_back(i[1]);
            parent[i[1]].push_back(i[0]);
        }
        vector<bool> visited(n, false);
        visited[0] = true;
        for(auto i:child[0]){
            queue<int> q;
            q.push(i);
            ret++;
            while(!q.empty()){
                int tmp = q.front();
                visited[tmp] = true;
                q.pop();
                for(auto j:child[tmp]){
                    if(!visited[j]){
                        q.push(j);
                        ret++;
                    }
                }
                for(auto j:parent[tmp]){
                    if(!visited[j]){
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
        for(auto i:parent[0]){
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int tmp = q.front();
                visited[tmp] = true;
                q.pop();
                for(auto j:child[tmp]){
                    if(!visited[j]){
                        q.push(j);
                        ret++;
                    }
                }
                for(auto j:parent[tmp]){
                    if(!visited[j]){
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
        return ret;
    }
};
