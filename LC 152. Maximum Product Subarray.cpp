class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int small = nums[0], big = nums[0], ret = nums[0];
        for(int i=1; i<nums.size(); i++){
            int tmp = small;
            small = min(nums[i], min(big*nums[i], small*nums[i]));
            big = max(nums[i], max(big*nums[i], tmp*nums[i]));
            ret = max(big,ret);
        }
        return ret;
    }
};
