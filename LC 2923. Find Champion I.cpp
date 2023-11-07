class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ret(n, true);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && grid[i][j] == 0){
                    ret[i] = false;
                }
            }
            if(ret[i]){
                return i;
            }
        }
        return -1;
    }
};
