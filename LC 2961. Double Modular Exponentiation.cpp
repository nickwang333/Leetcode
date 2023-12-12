class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ret;
        int n = variables.size();
        for(int i=0; i<n; i++){
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];
            int tmp = a;
            for(int j=1; j<b; j++){
                tmp %= 10;
                tmp *= a;
            }
            tmp %= 10;
            int tmp2 = tmp;
            for(int j=1; j<c; j++){
                tmp *= tmp2;
                tmp %= m;
            }
            tmp %= m;
            if(target == tmp){
                ret.push_back(i);
            }
        }
        return ret;
    }
};
