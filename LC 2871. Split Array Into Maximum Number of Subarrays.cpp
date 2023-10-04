class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int n = nums.size(), min = nums[0], ret = 0, tmp = -1;
        for(int i:nums){
            min &= i;
        }
        if(min > 0){
            return 1;
        }
        for(int i=0; i<n; i++){
            if(tmp == -1){
                tmp = nums[i];
            }
            tmp &= nums[i];
            if(tmp == min){
                ret++;
                tmp = -1;
            }
        }
        return ret;
    }
};
