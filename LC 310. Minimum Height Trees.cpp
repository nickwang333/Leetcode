class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int one_last;
        if(n == 1){
            vector<int> ret{0};
            return ret;
        }
        else if(n == 2){
            vector<int> ret{0,1};
            return ret;
        }
        vector<int> ret;
        queue<int> q;
        unordered_map<int, int> degrees, visited;
        unordered_map<int, unordered_map<int, int>> adj;
        for(auto i:edges){
            degrees[i[0]]++;
            degrees[i[1]]++;
            adj[i[0]][i[1]] = 1;
            adj[i[1]][i[0]] = 1;
        }
        for(auto i:degrees){
            if(i.second == 1){
                q.push(i.first);
            }
        }

        while(n > 2){
            auto tmpDegree = degrees;
            while(!q.empty() && n > 2){
                int sz = q.size();
                for(int i=0; i<sz; i++){
                    int tmp = q.front();
                    q.pop();
                    n--;
                    for(auto j:adj[tmp]){
                        if(j.second == 1){
                            adj[j.first][tmp] = 0;
                            degrees[j.first]--;
                            degrees[tmp] = 0;
                            one_last = j.first;
                            if(degrees[j.first] == 1){
                                q.push(j.first);
                            }
                            else if(degrees[j.first] == 0){
                                ret.push_back(j.first);
                                return ret;
                            }
                        }
                    }
                }
            }
        }
        for(auto i:degrees){
            if(i.second != 0){
                ret.push_back(i.first);
            }
        }
        return ret;
    }
};
