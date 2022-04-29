class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ret;
        ret.push_back(mat[0][0]);
        int m = mat.size(), n = mat[0].size(), i = 0, j = 0;
        char d = 'u';
        while(i != m-1 || j != n-1){
            if(i == 0 && j != n-1 && d == 'u'){
                j++;
                d = 'd';
            }
            else if(j == 0 && i != m-1 && d == 'd'){
                i++;
                d = 'u';
            }
            else if(i == m-1 && d == 'd'){
                d = 'u';
                j++;
            }
            else if(j == n-1 && d == 'u'){
                d = 'd';
                i++;
            }
            else if(d == 'u'){
                i--;
                j++;
            }
            else{
                i++;
                j--;
            }
            ret.push_back(mat[i][j]);
        }
        return ret;
    }
};
