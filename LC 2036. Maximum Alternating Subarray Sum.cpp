class Solution {
public:
    long long max(long long a, long long b){
        if(a>b){
            return a;
        }
        return b;
    }
    
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> dp(n), dp2(n);
        dp[0] = nums[0];
        dp2[0] = 0;
        long long ret = 0;
        ret = nums[0];
        for(int i=1; i<n; i++){
            long long tmp = dp2[i-1];
            dp2[i] = max(dp[i-1]-nums[i], 0);
            dp[i] = max(tmp+nums[i], nums[i]);
            ret = max(ret, max(dp2[i], dp[i]));
        }
        return ret;
    }
};
