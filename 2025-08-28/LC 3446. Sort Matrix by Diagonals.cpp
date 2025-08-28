class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> ret = grid;
        unordered_map<int, vector<int>> m;
        int n = grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                m[i-j].push_back(grid[i][j]);
            }
        }
        for(auto it:m){
            if(it.first >= 0){
                sort(it.second.rbegin(), it.second.rend());
                for(int i=0; i<it.second.size(); i++){
                    ret[i+it.first][i] = it.second[i];
                }
            }
            else{
                sort(it.second.begin(), it.second.end());
                for(int i=0; i<it.second.size(); i++){
                    ret[i][i-it.first] = it.second[i];
                }
            }
        }
        return ret;
    }
};
