class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), ret = 1;
        vector<int> row(2, 1);
        vector<vector<int>> dp(n, row);
        for(int i=1; i<n; i++){
            if(nums1[i] >= nums1[i-1]){
                dp[i][0] = dp[i-1][0]+1;
            }
            if(nums1[i] >= nums2[i-1]){
                dp[i][0] = max(dp[i][0], dp[i-1][1]+1);
            }
            if(nums2[i] >= nums1[i-1]){
                dp[i][1] = dp[i-1][0]+1;
            }
            if(nums2[i] >= nums2[i-1]){
                dp[i][1] = max(dp[i][1], dp[i-1][1]+1);
            }
            ret = max(ret, max(dp[i][0],dp[i][1]));
        }
        return ret;
    }
};
