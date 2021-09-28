class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ret = 0;
        vector<int> row(n,0);
        vector<vector<int>> v(n,row);
        for(int i=0; i<n; i++){
            for(int j=i; j>=0; j--){
                if(j==i){
                    v[i][j] = 1;
                }
                else if(s[i]==s[j] && i-j==1){
                     v[i][j] = 1;
                }
                else if(s[i]==s[j]){
                    v[i][j] += v[i-1][j+1];
                }
            }
        }
        for(auto i:v){
            for(int j:i){
                ret += j;
            }
        }
        return ret;
    }
};
