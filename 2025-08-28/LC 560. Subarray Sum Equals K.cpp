class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), total = 0, ret = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for(int i=0; i<n; i++){
            total += nums[i];
            ret += m[total - k];
            m[total]++;
        }
        return ret;
    }
};
