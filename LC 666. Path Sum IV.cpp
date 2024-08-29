class Solution {
public:
    int pathSum(vector<int>& nums) {
        int ret = 0;
        vector<int> v1(1, -1);
        vector<int> v5(2, -1);
        vector<int> v3(4, -1);
        vector<int> v4(8, -1);
        vector<vector<int>> v{v1, v5, v3, v4};
        vector<vector<int>> v2{v1, v5, v3, v4};
        for(int i:nums){
            int d1 = i / 100;
            i %= 100;
            int d2 = i / 10;
            i %= 10;
            int d3 = i;
            v[d1-1][d2-1] = d3;
        }
        for(int i=3; i>=0; i--){
            for(int j=0; j<v2[i].size(); j++){
                if(v[i][j] != -1){
                    if(v2[i][j] == -1){
                        v2[i][j] = 1;
                    }
                    if(i != 0){
                        if(v2[i-1][j/2] == -1){
                            v2[i-1][j/2] = v2[i][j];
                        }
                        else{
                            v2[i-1][j/2] += v2[i][j];
                        }
                    }
                    ret += (v[i][j] * v2[i][j]);
                }
            }
        }
        return ret;
    }
};
