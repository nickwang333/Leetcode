bool check(int i, int j, vector<vector<int>>& v){
    int m = v.size(), n = v[0].size();
    if(i>=0 && i<m && j>=0 && j<n && v[i][j] == -1){
        return true;
    }
    return false;
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int i=0, j=0, command = 1;
        vector<int> ret, row(n,-1);
        vector<vector<int>> v(m,row);
        ret.push_back(matrix[i][j]);
        v[i][j] = 1;
        while(ret.size()<m*n){
            if(command==1){
                while(check(i,j+1,v)){
                    v[i][j+1] = 1;
                    ret.push_back(matrix[i][j+1]);
                    j++;
                }
                command = 2;
            }
            else if(command==2){
                while(check(i+1,j,v)){
                    v[i+1][j] = 1;
                    ret.push_back(matrix[i+1][j]);
                    i++;
                }
                command = 3;
            }
            else if(command==3){
                while(check(i,j-1,v)){
                    v[i][j-1] = 1;
                    ret.push_back(matrix[i][j-1]);
                    j--;
                }
                command = 4;
            }
            else if(command==4){
                while(check(i-1,j,v)){
                    v[i-1][j] = 1;
                    ret.push_back(matrix[i-1][j]);
                    i--;
                }
                command = 1;
            }
        }
        return ret;
    }
};
