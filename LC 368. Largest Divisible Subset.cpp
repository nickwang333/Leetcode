class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), high = 1;
        vector<vector<int>> dp(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                if(j==i){
                    dp[i].push_back(nums[i]);
                    int tmp = dp[i].size();
                    high = max(high, tmp);
                }
                else{
                    if(nums[i]%nums[j]==0){
                        int tmp1 = dp[i].size();
                        int tmp2 = dp[j].size();
                        if(tmp1<=tmp2){
                            dp[i] = dp[j];
                        }
                    
                    }
                }
            }
        }
        for(auto i:dp){
            if(high == i.size()){
                return i;
            }
        }
        return dp[0];
    }
};
