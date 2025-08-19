class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), total = 0, ret = nums[0];
        for(int i=0; i<n; i++){
            total += nums[i];
            ret = max(total, ret);
            if(total < 0){
                total = 0;
            }
        }
        return ret;
    }
};
