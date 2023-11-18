class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int left = 0, ret = 1, n = nums.size();
        long pro = 0, tsum = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            tsum += nums[i];
            long pro = long(i-left+1)*long(nums[i]) - tsum;
            while(pro > k){
                tsum -= nums[left];
                left++;
                pro = long(i-left+1)*long(nums[i]) - tsum;
            }
            ret = max(ret, i-left+1);
            
        }
        return ret;
    }
};
