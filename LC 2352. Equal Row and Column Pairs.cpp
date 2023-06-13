class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> row, col;
        int ret = 0;
        int n = grid.size();
        for(int i=0; i<n; i++){
            string tmp = "";
            for(int j=0; j<n; j++){
                tmp += to_string(grid[i][j]);
                tmp += " ";
            }
            row[tmp]++;
        }
        for(int i=0; i<n; i++){
            string tmp = "";
            for(int j=0; j<n; j++){
                tmp += to_string(grid[j][i]);
                tmp += " ";
            }
            col[tmp]++;
        }
        for(auto i:row){
            ret += (i.second * col[i.first]);
        }
        return ret;
    }
};
