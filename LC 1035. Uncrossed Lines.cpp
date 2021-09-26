class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B){
        int m = A.size(), n = B.size();
        vector<int> row(n+1,0);
        vector<vector<int>> v(m+1, row);
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(A[i-1]==B[j-1]){
                    v[i][j] = v[i-1][j-1]+1;
                }
                else{
                    v[i][j] = max(v[i-1][j], v[i][j-1]);
                }
            }
        }
        return v[m][n];
    }
};
