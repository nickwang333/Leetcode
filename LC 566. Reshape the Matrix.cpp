class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if(m*n != r*c){
            return mat;
        }
        vector<int> col(c, 0);
        vector<vector<int>> ret(r, col);
        int a = 0, b = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                ret[i][j] = mat[a][b];
                if(b == n-1){
                    b=0;
                    a++;
                }
                else{
                    b++;
                }
            }
        }
        return ret;
    }
};
