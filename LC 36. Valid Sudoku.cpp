class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            vector<int> row(9,0);
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    if(row[board[i][j]-'1'] == 1){
                        return false;
                    }
                    row[board[i][j]-'1']++;
                }
            }
        }
        for(int i=0; i<9; i++){
            vector<int> row(9,0);
            for(int j=0; j<9; j++){
                if(board[j][i] != '.'){
                    if(row[board[j][i]-'1'] == 1){
                        return false;
                    }
                    row[board[j][i]-'1']++;
                }
            }
        }
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                vector<int> row(9,0);
                if(board[i*3+1][j*3] != '.'){
                    if(row[board[i*3+1][j*3]-'1'] == 1){
                        return false;
                    }
                    row[board[i*3+1][j*3]-'1']++;
                }
                if(board[i*3][j*3] != '.'){
                    if(row[board[i*3][j*3]-'1'] == 1){
                        return false;
                    }
                    row[board[i*3][j*3]-'1']++;
                }
                if(board[i*3+2][j*3] != '.'){
                    if(row[board[i*3+2][j*3]-'1'] == 1){
                        return false;
                    }
                    row[board[i*3+2][j*3]-'1']++;
                }
                if(board[i*3+1][j*3+1] != '.'){
                    if(row[board[i*3+1][j*3+1]-'1'] == 1){
                        return false;
                    }
                    row[board[i*3+1][j*3+1]-'1']++;
                }
                if(board[i*3][j*3+1] != '.'){
                    if(row[board[i*3][j*3+1]-'1'] == 1){
                        return false;
                    }
                    row[board[i*3][j*3+1]-'1']++;
                }
                if(board[i*3+2][j*3+1] != '.'){
                    if(row[board[i*3+2][j*3+1]-'1'] == 1){
                        return false;
                    }
                    row[board[i*3+2][j*3+1]-'1']++;
                }
                if(board[i*3+1][j*3+2] != '.'){
                    if(row[board[i*3+1][j*3+2]-'1'] == 1){
                        return false;
                    }
                    row[board[i*3+1][j*3+2]-'1']++;
                }
                if(board[i*3][j*3+2] != '.'){
                    if(row[board[i*3][j*3+2]-'1'] == 1){
                        return false;
                    }
                    row[board[i*3][j*3+2]-'1']++;
                }
                if(board[i*3+2][j*3+2] != '.'){
                    if(row[board[i*3+2][j*3+2]-'1'] == 1){
                        return false;
                    }
                    row[board[i*3+2][j*3+2]-'1']++;
                }
            }
        }
        return true;
    }
};
