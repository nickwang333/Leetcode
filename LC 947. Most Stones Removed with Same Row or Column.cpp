class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int ret = 0;
        unordered_map<int, vector<vector<int>>> mr, mc;
        map<vector<int>, int> visited;
        for(auto i:stones){
            mr[i[0]].push_back(i);
            mc[i[1]].push_back(i);
            visited[i] = 0;
        }
        for(auto i:stones){
            queue<vector<int>> q;
            if(visited[i] == 0){
                q.push(i);
                visited[i] = 1;
                while(!q.empty()){
                    vector<int> v = q.front();
                    q.pop();
                    for(auto j:mr[v[0]]){
                        if(visited[j] == 0){
                            q.push(j);
                            visited[j] = 1;
                        }
                    }
                    for(auto j:mc[v[1]]){
                        if(visited[j] == 0){
                            q.push(j);
                            visited[j] = 1;
                        }
                    }
                }
                ret++;
            }
        }
        ret = stones.size()-ret;
        return ret;
    }
};
