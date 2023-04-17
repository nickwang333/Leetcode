class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size(), maxi = nums[0], tsum = 0;
        vector<long long> ret(n, 0);
        for(int i=0; i<n; i++){
            ret[i] += nums[i];
            maxi = max(maxi, nums[i]);
            ret[i] += maxi;
            if(i != 0){
                ret[i] += ret[i-1];
            }
        }
        return ret;
    }
};
