class Solution {
    int compare(vector<vector<int>>& img1, vector<vector<int>>& img2, int h, int w){
        int n = img1.size();
        int ret = 0, tmp1 = 0, tmp2 = 0, tmp3 = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if((i+h)<n && (j+w)<n){
                    ret += (img1[i][j] & img2[(i+h)][(j+w)]);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if((i+h)<n && (j-w)>=0){
                    tmp2 += (img1[i][j] & img2[(i+h)][(j-w)]);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if((i-h)>=0 && (j+w)<n){
                    tmp3 += (img1[i][j] & img2[(i-h)][(j+w)]);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if((i-h)>=0 && (j-w)>=0){
                    tmp1 += (img1[i][j] & img2[(i-h)][(j-w)]);
                }
            }
        }
        return max(max(tmp2, tmp3),max(ret, tmp1));
    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxi = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int tmp = compare(img1, img2, i, j);
                //cout << tmp << " ";
                maxi = max(tmp, maxi);
            }
        }
        return maxi;
    }
};
