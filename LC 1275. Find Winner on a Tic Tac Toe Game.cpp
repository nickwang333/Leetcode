class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<char> row(3, ' ');
        vector<vector<char>> board(3,row);
        for(int i=0; i<moves.size(); i++){
            if(i%2==0){
                board[moves[i][0]][moves[i][1]] = 'A';
            }
            else{
                board[moves[i][0]][moves[i][1]] = 'B';
            }
        }
        for(int i=0; i<3; i++){
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] == 'A'){
                return "A";
            }
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i]== 'A'){
                return "A";
            }
        }
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1]  == 'A'){
            return "A";
        }
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1]  == 'B'){
            return "B";
        }
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1]  == 'A'){
            return "A";
        }
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1]  == 'B'){
            return "B";
        }
        for(int i=0; i<3; i++){
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] == 'B'){
                return "B";
            }
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i]== 'B'){
                return "B";
            }
        }
        for(auto i:board){
            for(char j:i){
                if(j== ' '){
                    return "Pending";
                }
            }
        }
        return "Draw";
    }
};
