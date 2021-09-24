class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int ret=0, high=0, n=nums.size();
        vector<int> dp1(n), dp2(n);
        for(int i=0; i<n; i++){
            if(i==0){
                high = nums[i];
                dp1[i] = nums[i];
                dp2[i] = nums[i]*nums[i];
                ret = dp2[i];
            }
            else{
                dp1[i] = max(dp1[i-1] + nums[i], nums[i]);
                dp2[i] = max(nums[i]*nums[i], max(dp2[i-1]+nums[i], dp1[i-1]+nums[i]*nums[i]));
                ret = max(ret, dp2[i]);
            }
        }
        return ret;
    }
};
