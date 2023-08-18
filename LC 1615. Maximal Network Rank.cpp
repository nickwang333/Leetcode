class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ret = 0;
        unordered_map<int, int> m;
        unordered_map<int, unordered_map<int, int>> m2;
        for(auto i:roads){
            m2[i[0]][i[1]] = 1;
            m2[i[1]][i[0]] = 1;
            m[i[0]]++;
            m[i[1]]++;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(m2[i][j] == 1){
                    ret = max(ret, m[i] + m[j]-1);
                }
                else{
                    ret = max(ret, m[i] + m[j]);
                }
            }
        }
        return ret;
    }
};
