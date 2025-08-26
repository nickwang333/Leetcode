class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ret = 0, maxi = 0;
        for(auto i:dimensions){
            int tmp = i[0] * i[0] + i[1] * i[1];
            if(tmp > maxi){
                maxi = tmp;
                ret = i[0] * i[1];
            }
            else if(tmp == maxi){
                ret = max(ret, i[0] * i[1]);
            }
        }
        return ret;
    }
};
