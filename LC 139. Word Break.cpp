class Solution {
public:
    bool wordBreak(string s, vector<string> &dict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=0; i<n; i++){
            if(dp[i]){
                for(string j:dict){
                    if(i+j.size()<=n){
                        string tmp = s.substr(i,j.size());
                        if(tmp==j){
                            dp[i+j.size()] = true;
                        }
                    }
                }
            }
        }
        return dp[n];
    }
};
