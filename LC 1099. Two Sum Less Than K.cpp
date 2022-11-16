class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int high = -1, n = nums.size();
        int ret = 0;
        for(int i=1; i<n; i++){
            if(nums[i]+nums[0] < k){
                high = i;
                ret = max(ret, nums[i]+nums[0]);
            }
        }
        if(high == -1){
            return -1;
        }
        for(int i=1; i<n; i++){
            while(high > i && nums[i]+nums[high] >= k){
                high--;
            }
            if(high == i){
                break;
            }
            ret = max(ret, nums[i]+nums[high]);
        }
        return ret;
    }
};
