class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ret = 0, tsum = 0;
        unordered_map<int, int> m2;
        int n = nums.size();
        for(int i=0; i<k; i++){
            tsum += nums[i];
            m2[nums[i]]++;
        }
        if(m2.size()>=m){
            ret = tsum;
        }
        for(int i=k; i<n; i++){
            tsum += nums[i];
            tsum -= nums[i-k];
            m2[nums[i]]++;
            m2[nums[i-k]]--;
            if(m2[nums[i-k]] == 0){
                m2.erase(nums[i-k]);
            }
            if(m2.size()>=m){
                ret = max(ret, tsum);
            }
        }
        return ret;
    }
};
