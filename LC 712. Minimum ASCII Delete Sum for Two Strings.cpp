class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int ret = 0, m = s1.size(), n = s2.size();
        vector<int> row(n+1,0);
        vector<vector<int>> v(m+1,row);
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]){
                    v[i][j] = v[i-1][j-1]+int(s1[i-1]);
                }
                else{
                    v[i][j] = max(v[i-1][j], v[i][j-1]);
                }
            }
        }
        for(char i:s1){
            ret += i;
        }
        for(char i:s2){
            ret += i;
        }
        return ret-2*v[m][n];
    }
};
