class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> row(n,0);
        vector<vector<int>> ret(n,row);
        int i=0, j=0, counter=1;
        while(counter <= n*n){
            while(j<n && ret[i][j]==0){
                ret[i][j] = counter;
                counter++;
                j++;
            }
            j--;
            i++;
            while(i<n && ret[i][j]==0){
                ret[i][j] = counter;
                counter++;
                i++;
            }
            i--;
            j--;
            while(j>=0 && ret[i][j]==0){
                ret[i][j] = counter;
                counter++;
                j--;
            }
            j++;
            i--;
            while(i>=0 && ret[i][j]==0){
                ret[i][j] = counter;
                counter++;
                i--;
            }
            j++;
            i++;
        }
        
        return ret;
    }
};
