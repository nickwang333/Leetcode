class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                int total = 0;
                if(grid[i+1][j+1] == 'W'){
                    total++;
                }
                if(grid[i][j+1] == 'W'){
                    total++;
                }
                if(grid[i+1][j] == 'W'){
                    total++;
                }
                if(grid[i][j] == 'W'){
                    total++;
                }
                if(total >= 3 || total <= 1){
                    return true;
                }
            }
        }
        return false;
    }
};
