class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<vector<int>> ret;
        queue<int> q;
        queue<vector<int>> path;
        vector<int> v1{0};
        q.push(0);
        path.push(v1);
        while(1){
            int n = q.size();
            if(n==0){
                break;
            }
            for(int i=0; i<n; i++){
                int tmp = q.front();
                vector<int> v2 = path.front();
                path.pop();
                q.pop();
                for(int j=0; j<graph[tmp].size(); j++){
                    vector<int> v3 = v2;
                    v3.push_back(graph[tmp][j]);
                    path.push(v3);
                    q.push(graph[tmp][j]);
                    if(graph[tmp][j]==m-1){
                        ret.push_back(v3);
                    }
                }
            }
        }
        return ret;
    }
};
