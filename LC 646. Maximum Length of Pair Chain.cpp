class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int ret = 1, n = pairs.size();
        vector<int> dp(n,1);
        sort(pairs.begin(), pairs.end());
        for(int i=1; i<pairs.size(); i++){
            for(int j=0; j<i; j++){
                if(pairs[i][0]>pairs[j][1]){
                    dp[i] = max(dp[j]+1, dp[i]);
                    ret = max(ret, dp[i]);
                }
            }
        }
        return ret;
    }
};
