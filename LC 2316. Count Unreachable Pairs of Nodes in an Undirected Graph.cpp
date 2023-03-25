class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ret = 0;
        unordered_map<int, unordered_map<int, int>> m;
        for(auto i:edges){
            m[i[0]][i[1]] = 1;
            m[i[1]][i[0]] = 1;
        }
        vector<vector<int>> v;
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                vector<int> tmp2;
                tmp2.push_back(i);
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while(!q.empty()){
                    int tmp = q.front();
                    q.pop();
                    for(auto it:m[tmp]){
                        if(!visited[it.first]){
                            q.push(it.first);
                            visited[it.first] = true;
                            tmp2.push_back(it.first);
                        }
                    }
                }
                v.push_back(tmp2);
            }
        }
        int total = n;
        for(auto i:v){
            total -= i.size();
            ret += (i.size() * total);
        }
        return ret;
    }
};
