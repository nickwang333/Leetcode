class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ret = img;
        int m = img.size(), n = img[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int tmp = img[i][j], counter = 1;
                if(i > 0 && j > 0){
                    tmp += img[i-1][j-1];
                    counter++;
                }
                if(i > 0){
                    tmp += img[i-1][j];
                    counter++;
                }
                if(j > 0){
                    tmp += img[i][j-1];
                    counter++;
                }
                if(i < m-1 && j < n-1){
                    tmp += img[i+1][j+1];
                    counter++;
                }
                if(i < m-1){
                    tmp += img[i+1][j];
                    counter++;
                }
                if(j < n-1){
                    tmp += img[i][j+1];
                    counter++;
                }
                if(i > 0 && j < n-1){
                    tmp += img[i-1][j+1];
                    counter++;
                }
                if(j > 0 && i < m-1){
                    tmp += img[i+1][j-1];
                    counter++;
                }
                ret[i][j] = tmp/counter;
            }
        }
        return ret;
    }
};
