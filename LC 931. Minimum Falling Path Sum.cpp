class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp = matrix;
        int n = matrix.size(), ret = INT_MAX;
        if(n == 1){
            return matrix[0][0];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                if(j > 0 && j < n-1){
                    matrix[i][j] += min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i-1][j+1]));
                }
                else if(j == 0){
                    matrix[i][j] += min(matrix[i-1][j+1], matrix[i-1][j]);
                }
                else if(j == n-1){
                    matrix[i][j] += min(matrix[i-1][j], matrix[i-1][j-1]);
                }
            }
        }
        for(int i:matrix[n-1]){
            ret = min(ret, i);
        }
        return ret;
    }
};
