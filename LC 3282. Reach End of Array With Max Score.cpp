class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ret = 0, prev = 0;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] > nums[prev]){
                ret +=((i - prev)* nums[prev]);
                prev = i;
            }
        }
        ret += ((n-1-prev) * nums[prev]);
        return ret;
    }
};
