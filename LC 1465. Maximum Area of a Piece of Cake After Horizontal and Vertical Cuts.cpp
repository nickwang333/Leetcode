class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int m = horizontalCuts.size(), n = verticalCuts.size(), ret = 0, high = 0, wide = 0;
        vector<int> ho(m+1), ve(n+1);
        ho[0] = horizontalCuts[0];
        ho[m] = h-horizontalCuts[m-1];
        ve[0] = verticalCuts[0];
        ve[n] = w-verticalCuts[n-1];
        for(int i=1; i<m; i++){
            ho[i] = horizontalCuts[i]-horizontalCuts[i-1];
        }
        for(int i=1; i<n; i++){
            ve[i] = verticalCuts[i]-verticalCuts[i-1];
        }
        for(int i:ho){
            high = max(i, high);
        }
        for(int i:ve){
            wide = max(i, wide);
        }
        return long(wide)*long(high)%1000000007;
    }
};
