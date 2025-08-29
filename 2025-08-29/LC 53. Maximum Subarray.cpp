class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tmp = 0, ret = nums[0];
        for(int i:nums){
            tmp = max(tmp, 0);
            tmp += i;
            ret = max(tmp, ret);
        }
        return ret;
    }
};
