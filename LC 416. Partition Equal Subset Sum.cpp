class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = 0;
        for(int i:nums){
            n += i;
        }
        if(n%2 == 1){
            return false;
        }
        n/=2;
        vector<bool> dp(n+1, false), dp_tmp;
        dp[0] = true;
        sort(nums.begin(), nums.end());
        for(int i:nums){
            dp_tmp = dp;
            for(int j=0; j<=n; j++){
                if(dp[j] && i+j<=n){
                    dp_tmp[i+j] = true;
                }
            }
            dp = dp_tmp;
        }
        return dp[n];
    }
};
