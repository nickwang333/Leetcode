class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, false);
        dp[0] = true;
        for(int i=0; i<n-1; i++){
            if(dp[i]){
                if(i == n-2){
                    if(nums[i] == nums[i+1]){
                        return true;
                    }
                }
                else if(i == n-3){
                    if(nums[i] == nums[i+1] && nums[i+1] == nums[i+2]){
                        return true;
                    }
                    else if(nums[i]+1 == nums[i+1] && nums[i+1]+1 == nums[i+2]){
                        return true;
                    }
                }
                else{
                    if(nums[i] == nums[i+1]){
                        dp[i+2] = true;
                    }
                    if(nums[i] == nums[i+1] && nums[i+1] == nums[i+2]){
                        dp[i+3] = true;
                    }
                    if(nums[i]+1 == nums[i+1] && nums[i+1]+1 == nums[i+2]){
                        dp[i+3] = true;
                    }
                }
            }
        }
        return dp[n];
    }
};
