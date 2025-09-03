class TicTacToe {
    int sz = 0, p1d = 0, p2d = 0, p1d2 = 0, p2d2 = 0;
    vector<int> p1r, p1c, p2r, p2c;
public:
    TicTacToe(int n) {
        sz = n;
        vector<int> row(n ,0);
        p1r = row;
        p1c = row;
        p2r = row;
        p2c = row;
    }
    
    int move(int row, int col, int player) {
        if(player == 1){
            p1r[row]++;
            p1c[col]++;
            if(row == col){
                p1d++;
            }
            if(row+col == sz-1){
                p1d2++;
            }
            if(p1d == sz || p1d2 == sz || p1r[row] == sz || p1c[col] == sz){
                return 1;
            }
        }
        else{
            p2r[row]++;
            p2c[col]++;
            if(row == col){
                p2d++;
            }
            if(row+col == sz-1){
                p2d2++;
            }
            if(p2d == sz || p2d2 == sz || p2r[row] == sz || p2c[col] == sz){
                return 2;
            }
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
