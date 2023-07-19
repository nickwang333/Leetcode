class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ret = 1, n = nums.size(), prev = 0;
        for(int i=1; i<n; i++){
            while(nums[i] - nums[prev] > 2*k){
                prev++;
            }
            ret = max(ret, i-prev+1);
        }
        return ret;
    }
};
