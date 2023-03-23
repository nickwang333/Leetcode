class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int sz = connections.size(), ret = 0;
        if(sz < n-1) {
            return -1;
        }
        unordered_map<int, unordered_map<int,int>> m;
        for(auto i:connections){
            m[i[0]][i[1]] = 1;
            m[i[1]][i[0]] = 1;
        }

        vector<int> connect(n,-1);
        for(int i=0; i<n; i++){
            if(connect[i] == -1){
                queue<int> q;
                q.push(i);
                connect[i] = 1;
                while(!q.empty()){
                    int tmp = q.front();
                    q.pop();
                    for(auto i=m[tmp].begin(); i!=m[tmp].end(); i++){
                        if(connect[i->first] == -1){
                            q.push(i->first);
                            connect[i->first] = 1;
                        }
                    }
                }
                ret++;
            }
        }
        return ret-1;
    }
};
