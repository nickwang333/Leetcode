class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = nums[1] - nums[0];
        for(int i=1; i<nums.size(); i++){
            ret = min(ret, nums[i] - nums[i-1]);
        }
        return ret;
    }
};
