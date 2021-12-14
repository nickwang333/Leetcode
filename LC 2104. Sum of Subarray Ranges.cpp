class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ret = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int ma = nums[i], mi = nums[i];
            for(int j=i+1; j<n; j++){
                ma = max(nums[j], ma);
                mi = min(nums[j], mi);
                ret += (ma-mi);
            }
        }
        return ret;
    }
};
