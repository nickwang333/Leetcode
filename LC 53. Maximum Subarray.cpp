class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), tsum = nums[0], ret = nums[0];
        vector<int> v(n,0);
        v[0] = nums[0];
        for(int i=1; i<n; i++){
            v[i] = max(nums[i], v[i-1]+nums[i]);
            ret = max(ret, v[i]);
        }
        return ret;
    }
};
