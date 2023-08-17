class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row(n,0);
        vector<vector<int>> ret(m, row);
        queue<vector<int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push(vector<int> {i,j});
                }
                else{
                    ret[i][j] = -1;
                }
            }
        }
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                vector<int> tmp = q.front();
                q.pop();
                if(tmp[0] > 0 && ret[tmp[0]-1][tmp[1]] == -1){
                    ret[tmp[0]-1][tmp[1]] = ret[tmp[0]][tmp[1]]+1;
                    q.push(vector<int> {tmp[0]-1, tmp[1]});
                }
                if(tmp[1] > 0 && ret[tmp[0]][tmp[1]-1] == -1){
                    ret[tmp[0]][tmp[1]-1] = ret[tmp[0]][tmp[1]]+1;
                    q.push(vector<int> {tmp[0], tmp[1]-1});
                }
                if(tmp[0] < m-1 && ret[tmp[0]+1][tmp[1]] == -1){
                    ret[tmp[0]+1][tmp[1]] = ret[tmp[0]][tmp[1]]+1;
                    q.push(vector<int> {tmp[0]+1, tmp[1]});
                }
                if(tmp[1] < n-1 && ret[tmp[0]][tmp[1]+1] == -1){
                    ret[tmp[0]][tmp[1]+1] = ret[tmp[0]][tmp[1]]+1;
                    q.push(vector<int> {tmp[0], tmp[1]+1});
                }
            }
        }
        return ret;
    }
};
