class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), ret = 0;
        vector<int> row(n+1,0);
        vector<vector<int>> ver(m+1,row), hor = ver, dia = ver, adia = ver;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(mat[i-1][j-1]==1){
                    ver[i][j] = ver[i-1][j]+1;
                    ret = max(ret, ver[i][j]);
                    hor[i][j] = hor[i][j-1]+1;
                    ret = max(ret, hor[i][j]);
                    dia[i][j] = dia[i-1][j-1]+1;
                    ret = max(ret, dia[i][j]);
                    if(j==n){
                        adia[i][j] = 1;
                    }
                    else{
                        adia[i][j] = adia[i-1][j+1]+1;
                    }
                    ret = max(ret, adia[i][j]);
                }
            }
        }
        return ret;
    }
};
