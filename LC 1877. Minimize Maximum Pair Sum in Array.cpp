class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size(), ret = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n/2; i++){
            ret = max(ret, nums[i] + nums[n-i-1]);
        }
        return ret;
    }
};
