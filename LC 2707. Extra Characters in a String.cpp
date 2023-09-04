class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n+1,0);
        for(int i=1; i<=n; i++){
            dp[i] = dp[i-1]+1;
            for(string j:dictionary){
                int sz = j.size();
                if(i-sz >= 0 && s.substr(i-sz, sz) == j){
                    dp[i] = min(dp[i-sz], dp[i]);
                }
            }
        }
        return dp[n];
    }
};
