class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        vector<int> ret;
        unordered_map<int, int> used;
        for(auto i:adjacentPairs){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int head = -1, n = adjacentPairs.size() + 1;
        for(auto i:adj){
            if(i.second.size() == 1){
                head = i.first;
                break;
            }
        }
        ret.push_back(head);
        used[head] = 1;
        for(int i=0; i<n-1; i++){
            for(int i:adj[head]){
                if(used[i] == 0){
                    used[i] = 1;
                    head = i;
                    ret.push_back(head);
                    break;
                }
            }
        }
        return ret;
    }
};
