class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(target+1, -1);
        dp[0] = 0;
        for(int i:nums){
            vector<int> dp2 = dp;
            for(int j=0; j<target; j++){
                if(dp[j] != -1 && (j+i) <= target){
                    if(dp2[i+j] == -1){
                        dp2[i+j] = dp[j] + 1;
                    }
                    else{
                        dp2[i+j] = max(dp2[i+j], dp[j]+1);
                    }
                }
            }
            dp = dp2;
        }
        return dp[target];
    }
};
