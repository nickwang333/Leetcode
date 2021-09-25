class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), high = 1, ret = 0;
        vector<int> v(n,1), dp(n,1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    if(v[i] < v[j]+1){
                        v[i] = v[j]+1;
                        dp[i] = dp[j];
                    }
                    
                    else if(v[i] == v[j]+1){
                        dp[i] += dp[j];
                    }
                    high = max(high,v[i]);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(v[i]==high){
                ret += dp[i];
            }
        }
        return ret;
    }
};
