class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size(), ret = 0;
        for(int i=0; i<n; i++){
            int tmp1 = colors[i];
            int tmp2 = colors[(i+1) % n];
            int tmp3 = colors[(i+2) % n];
            if(tmp1 != tmp2 && tmp2 != tmp3){
                ret++;
            }
        }
        return ret;
    }
};
