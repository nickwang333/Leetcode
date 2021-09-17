bool check_valid(int i, int j, vector<vector<char>>& board, vector<vector<int>>& v){
    int m = board.size(), n = board[0].size();
    if(i>=0 && i<m && j>=0 && j<n && v[i][j]==-1 && board[i][j]=='O'){
        v[i][j] = 1;
        return true;
    }
    return false;
}

void bfs(queue<vector<int>>& q, vector<vector<char>>& board, vector<vector<int>>& v){
    while(!q.empty()){
        vector<int> tmp = q.front(), tmp2(2);
        q.pop();
        if(check_valid(tmp[0]+1, tmp[1], board, v)){
            tmp2[0] = tmp[0]+1;
            tmp2[1] = tmp[1];
            q.push(tmp2);
        }
        if(check_valid(tmp[0], tmp[1]+1, board, v)){
            tmp2[0] = tmp[0];
            tmp2[1] = tmp[1]+1;
            q.push(tmp2);
        }
        if(check_valid(tmp[0]-1, tmp[1], board, v)){
            tmp2[0] = tmp[0]-1;
            tmp2[1] = tmp[1];
            q.push(tmp2);
        }
        if(check_valid(tmp[0], tmp[1]-1, board, v)){
            tmp2[0] = tmp[0];
            tmp2[1] = tmp[1]-1;
            q.push(tmp2);
        }
    }
}

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<int> row(n,-1);
        vector<vector<int>> v(m,row);
        queue<vector<int>> q;
        for(int i=0; i<m; i++){
            if(check_valid(i,0,board,v)){
                v[i][0] = 1;
                vector<int> tmp{i,0};
                q.push(tmp);
                bfs(q,board,v);
            }
            if(check_valid(i,n-1,board,v)){
                v[i][n-1] = 1;
                vector<int> tmp{i,n-1};
                q.push(tmp);
                bfs(q,board,v);
            }
        }
        for(int i=0; i<n; i++){
            if(check_valid(0,i,board,v)){
                v[0][i] = 1;
                vector<int> tmp{0,i};
                q.push(tmp);
                bfs(q,board,v);
            }
            if(check_valid(m-1,i,board,v)){
                v[m-1][i] = 1;
                vector<int> tmp{m-1,i};
                q.push(tmp);
                bfs(q,board,v);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(v[i][j]==-1){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
