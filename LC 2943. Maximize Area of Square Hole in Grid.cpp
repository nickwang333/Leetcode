class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int maxm = 1, maxn = 1, tmp = 1;
        for(int i=0; i<hBars.size()-1; i++){
            if(hBars[i+1] - hBars[i] == 1){
                tmp++;
            }
            else{
                maxm = max(maxm, tmp+1);
                tmp = 1;
            }
        }
        maxm = max(maxm, tmp+1);
        tmp = 1;
        for(int i=0; i<vBars.size()-1; i++){
            if(vBars[i+1] - vBars[i] == 1){
                tmp++;
            }
            else{
                maxn= max(maxn, tmp+1);
                tmp = 1;
            }
        }
        maxn= max(maxn, tmp+1);
        return min(maxm, maxn) * min(maxm, maxn);
    }
};
