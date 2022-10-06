class Solution {
public:
    int deleteString(string s) {
        int n = s.size(), counter = 0, ret = 1;
        vector<int> v(n,0);
        vector<vector<int>> dp(n,v);
        vector<int> dp2(n+1, 0);
        dp2[0] = 1;
        queue<int> q;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j]){
                    if(i == 0 || j == 0){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = dp[i-1][j-1]+1;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            if(dp2[i] != 0){
                for(int j=1; j<n; j++){
                    if(i+j+j <= n){
                        if(dp[i+j-1][i+j+j-1] >= j){
                            dp2[i+j] = dp2[i]+1;
                        }
                    }
                }
            }
        }
        for(int i:dp2){
            ret = max(ret, i);
        }
        return ret;
    }
};
