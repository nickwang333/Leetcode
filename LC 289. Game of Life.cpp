class Solution {
public:
    bool live(vector<vector<int>>& board, int a, int b){
        int n = board.size(), m = board[0].size(), count = 0;
        for(int i = max(0,a-1); i<=min(n-1,a+1); i++){
            for(int j = max(0, b-1); j<=min(m-1, b+1); j++){
                if(i != a || j != b){
                    if(board[i][j] > 3){
                        count -= 4;
                    }
                    else if(board[i][j] > 1){
                        count -= 2;
                    }
                    count += board[i][j];
                    
                }
            }
        }
        if(board[a][b] == 1 || board[a][b] == 3 || board[a][b] == 5){
            if((count == 2) || (count == 3)){
                return true;
            }
        }
        else{
            return count == 3;
        }
        return false;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(live(board, i, j)){
                    if(board[i][j] == 1){
                        board[i][j] = 3;
                    }
                    else{
                        board[i][j] = 2;
                    }
                }
                else{
                    if(board[i][j] == 1){
                        board[i][j] = 5;
                    }
                    else{
                        board[i][j] = 4;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] > 3){
                    board[i][j] = 0;
                }
                else{
                    board[i][j] = 1;
                }
            }
        }
    }
};
