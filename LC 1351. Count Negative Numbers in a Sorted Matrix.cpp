class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ret = 0;
        for(auto i:grid){
            for(int j:i){
                if(j<0){
                    ret++;
                }
            }
        }
        return ret;
    }
};
