class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int, vector<int>> m;
        unordered_map<int, int> res;
        for(int i:restricted){
            res[i] = 1;
        }
        int ret = 1;
        vector<bool> v(n, false);
        for(auto i:edges){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        queue<int> q;
        v[0] = true;
        for(int i:m[0]){
            if(res[i] != 1){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            ret++;
            int tmp = q.front();
            q.pop();
            v[tmp] = true;
            for(int i:m[tmp]){
                if(!v[i] && res[i] != 1){
                    q.push(i);
                }
            }
        }
        return ret;
    }
};
